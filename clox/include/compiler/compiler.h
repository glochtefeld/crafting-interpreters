#ifndef CLOX_COMPILER_H
#define CLOX_COMPILER_H

#include "object.h"
#include "vm/vm.h"

ObjFunction* compile(const char* source);
void markCompilerRoots();

#endif
