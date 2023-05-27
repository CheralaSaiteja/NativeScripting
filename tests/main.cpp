#include "NativeScripting.hpp"
int main() {
  printf("Hello world hello\n");
  const char *lPath = "build/libtestLib.so";
  int lCount = 0;
  void *handle = CreateHandle(lPath);
  char **names = GetFunctionNames(lPath, &lCount);

  for (int i = 0; i < lCount; i++) {
    void (*Func)() = (void (*)())GetFunctionV(handle, names[i]);
    Func();
  }

  free(names);
  return 0;
}
