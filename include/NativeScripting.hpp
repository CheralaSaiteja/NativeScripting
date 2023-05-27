#ifndef NATIVESCRIPTING_HPP
#define NATIVESCRIPTING_HPP

#include <dlfcn.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

char *strrev(char *str);

void GetFunctionCount(FILE *fd, int *_count);
int GetFunctionCount(FILE *fd);

void *CreateHandle(const char *_sharedLibraryPath);
void Createhandle(const char *_sharedLibraryPath, void *_handle);

void DestroyHandle(void *_handle);

void *GetFunctionV(void *_handle, const char *_functionName);
void GetFunctionV(void *_handle, void *_fp, const char *_functionName);

char **GetFunctionNames(const char *_sharedLibraryPath, int *_functionCount);

uint8_t CheckForUpdates(const char *_sharedLibraryPath, int *_fCount);
#endif