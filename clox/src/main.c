#include "common.h"
#include "chunk/chunk.h"
#include "debug/debug.h"
#include "vm/vm.h"

int main(int argc, const char* argv[]) {
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 3);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_MULTIPLY, 1);

    constant = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_ADD, 1);

    constant = addConstant(&chunk, 4);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 5);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_NEGATE, 1);

    writeChunk(&chunk, OP_DIVIDE, 1);

    writeChunk(&chunk, OP_SUBTRACT, 1);

    
    writeChunk(&chunk, OP_RETURN, 1);

    disassembleChunk(&chunk, "Test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}

/* Challenge 1:
 *  1 * 2 + 3
 *  int constant = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_MULTIPLY, 1);

    constant = addConstant(&chunk, 3);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_ADD, 1);

 *  1 + 2 * 3
 *  int constant = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 3);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_MULTIPLY, 1);

    constant = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_ADD, 1);

 *  3 - 2 - 1
 *  int constant = addConstant(&chunk, 3);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_SUBTRACT, 1);

    constant = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_SUBTRACT, 1);

 *  1 + 2 * 3 - 4 / 5
 *  int constant = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 3);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_MULTIPLY, 1);

    constant = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_ADD, 1);

    constant = addConstant(&chunk, 4);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    constant = addConstant(&chunk, 5);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_NEGATE, 1);

    writeChunk(&chunk, OP_DIVIDE, 1);

    writeChunk(&chunk, OP_SUBTRACT, 1);

* Challenge 2:
* 4 - 3 * -2 Without OP_NEGATE: 4 - (3 * (0 - 2))
*/
