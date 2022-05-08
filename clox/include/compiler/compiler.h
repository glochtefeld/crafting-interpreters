#ifndef CLOX_COMPILER_H
#define CLOX_COMPILER_H

#include "object.h"
#include "vm/vm.h"

bool compile(const char* source, Chunk* chunk);

#endif
