#include "../include/common.h"
#include "../include/chunk/chunk.h"
#include "../include/debug/debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "Test chunk");
    freeChunk(&chunk);
    return 0;
}