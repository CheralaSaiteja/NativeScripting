#include "NativeScripting.hpp"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <dlfcn.h>

#define DEBUG

// max length of line in file that has function names of shared objects
#define MAX_LINE_LEN 512

char *strrev(char *str) {
  char *p1, *p2;

  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

void *CreateHandle(const char *_sharedLibraryPath) {
  return dlopen(_sharedLibraryPath, RTLD_LAZY);
}
void Createhandle(const char *_sharedLibraryPath, void *_handle) {
  _handle = dlopen(_sharedLibraryPath, RTLD_LAZY);
}

char buffer[MAX_LINE_LEN];
void GetFunctionCount(FILE *fd, int *_count) {
#ifdef DEBUG
  if (fd == NULL)
    return;
#endif
  *_count = 0;

  fseek(fd, 0, SEEK_SET);

  while (fgets(buffer, sizeof(buffer), fd)) {
    *_count += 1;
  }

  fseek(fd, 0, SEEK_SET);
}
int GetFunctionCount(FILE *fd) {

#ifdef DEBUG
  if (fd == NULL)
    return 0;
#endif
  int _count = 0;

  fseek(fd, 0, SEEK_SET);

  while (fgets(buffer, sizeof(buffer), fd)) {
    _count += 1;
  }

  fseek(fd, 0, SEEK_SET);
  return _count;
}

void DestroyHandle(void *_handle) { dlclose(_handle); }

void *GetFunctionV(void *_handle, const char *_functionName) {
  return dlsym(_handle, _functionName);
}
void GetFunctionV(void *_handle, void *_fp, const char *_functionName) {
  _fp = dlsym(_handle, _functionName);
}

char **GetFunctionNames(const char *_sharedLibraryPath, int *_functionCount){
  char *tStr;
  char **rStr;
  tStr = (char *)malloc(sizeof(char) * strlen(_sharedLibraryPath));
  strcpy(tStr, _sharedLibraryPath);
  tStr = strtok(tStr, ".");
  strcat(tStr, ".txt");

  FILE *fd = fopen(tStr, "r");
  free(tStr);
  *_functionCount = GetFunctionCount(fd);

  rStr = (char **)malloc(sizeof(char *) * (*_functionCount));
  for (int i = 0; i < *_functionCount; i++) {
    fgets(buffer, sizeof(buffer), fd);
    buffer[strlen(buffer) - 1] = '\0';
    rStr[i] = (char *)malloc(sizeof(char) * strlen(buffer));
    strcpy(rStr[i], buffer);
    printf("%s\n", rStr[i]);
  }

  return rStr;
}

uint8_t CheckForUpdates(const char *_sharedLibraryPath, int *_fCount) {}