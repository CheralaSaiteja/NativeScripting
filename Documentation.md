# **Documentation**
## **Core API**
```cpp
// Create Handle
void* Createhandle(const char* _sharedLibraryPath);
```
```cpp
// Destroy Handle
void DestroyHandle(void * _handle);
```
```cpp
// Retreive a void function from library
void* GetFunctionV(void* _handle, const char* _functionName);
void GetFunctionV(void* _handle, void* _fp, const char* _functionName);
```
## **Utilities**
```cpp
// reverses a strig(char[])
char* strrev(char* _str);
```
```cpp
// Get Function Cout from <Library>.txt
void GetFunctionCount(FILE *fd, int *_count);
int GetFunctionCount(FILE *fd);
```
```cpp
// Get number of functions in a library
// Every Library has another file <Library>.txt which has all function names
void* GetFunctionV(void* _handle, const char* _functionName);
void GetFunctionV(void* _handle, void* _fp, const char* _functionName);
```
```cpp
// Retrieve all function names from respective <Library>.txt
char** GetFunctionNames(const char* _sharedLibraryPath, int* _functionCount);
char** GetFunctionNames(const char* _sharedLibraryPath);
// NOTE : don't forget to clear return string array
```
```cpp
// check for any changes in the library
// It only checks if a function is removed or added
uint8_t CheckForUpdates(const char* _sharedLibraryPath);
// NOTE : doesn't consider changes in the logic of functions
```

## **Tutorial**
**Example 1**
```cpp
// global variables
void* lHandle;
int lCount = 0;
char** lNames;
const char* lPath = "path/to/.so";

// Get library handle
lHandle = CreateHandle(lPath);

// Get nmaes
lNames = GetFunctionNames(lPath, &lCount);

// retrieve and call
for (int i = 0; i < lCount; i++) {
  void (*Func)() = (void (*)())GetFunctionV(lHandle, lNames[i]);
  Func();
}

// free
free(lNames);
```
**Example 2**
```cpp
// create a sruct to store all library related data
struct LibraryHandle{
    char* LibraryPath;
    void* Handle;
    char** Names;
    std::vector<void(*)()> FunctionPointers;
    int FunctionCount;
};

// create instance of struct LibraryHandle
struct LibraryHandle libraryHandle;

// create a temp variable to store library path
const char* lPath = "path/to/youlib.so";

// alocate memory
libraryHandle.LibraryPath = (char*)malloc(sizeof(char) * strlen(lPath));

// copy lPath data to struct
strcpy(libraryHandle.LibraryPath, lPath);

// Get library handle
libraryHandle.Handle = CreateHandle(libraryHandle.LibraryPath);

// Get functions count
GetFunctionCount("path/to/youlib.so", &libraryHandle.FunctionCount);

// Get function names
libraryHandle.Names = GetFunctionNames(libraryHandle.LibraryPath, &libraryHandle.FunctionCount);

// Retrieve all functions 
for(int i = 0; i < libraryHandle.FunctionCount; i++){
    libraryHandle.FunctionPointers.push_back((void(*)())GetFunctionV(libraryHandle.Handle, libraryHandle.Names[i]));
}

// Usage
//
// Find function by name and call it
//
// reference with index of pointers and calling 
//

// destroy handle and cleanup
DestroyHandle(libraryHandle.Handle);
free(libraryHandle.Names);
libraryHandle.FunctionPointers.clear();
```