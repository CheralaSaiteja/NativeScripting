#include <stdio.h>

extern "C" {
void printString() { printf("Hello dynamically loaded print function\n"); }
void printVersionString() { printf("Native Scripting Version 0.1a\n"); }
void AnotherFunction(){}
}