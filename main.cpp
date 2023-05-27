#include "NativeScripting.hpp"
int main() {
  printf("Hello world\n");
  const char *lPath = "bin/libmain.so";
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
