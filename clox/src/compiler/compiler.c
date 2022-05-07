#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "compiler/compiler.h"
#include "scanner/scanner.h"

typedef struct {
    Token current;
    Token previous;
    bool hadError;
    bool panicMode;
} Parser;

Parser parser;
Chunk* compilingChunk;

static Chunk* currentChunk() {
    return compilingChunk;
}

static void advance();
static void consume(TokenType type, const char* message);
static void emitByte(uint8_t byte);
static void emitReturn();
static void emitBytes(uint8_t byte1, uint8_t byte2);
static void endCompiler();
static void error(const char* message);
static void errorAt(Token* token, const char* message);
static void errorAtCurrent(const char* message);

bool compile(const char* source, Chunk* chunk) {
    initScanner(source);
    parser.hadError = false;
    parser.panicMode = false;
    compilingChunk = chunk;
    advance();
    expression();
    consume(TOKEN_EOF, "Expect end of expression.");
    endCompiler();
    return !parser.hadError;
}

static void advance() {
    parser.previous = parser.current;
    for (;;) {
        parser.current = scanToken();
        if (parser.current.type == TOKEN_ERROR) break;
        errorAtCurrent(parser.current.start);
    }
}

static void errorAtCurrent(const char* message) {
    errorAt(&parser.current, message);
}

static void error(const char* message) {
    errorAt(&parser.previous, message);
}

static void errorAt(Token* token, const char* message) {
    if (parser.panicMode) return;
    parser.panicMode = true;
    fprintf(stderr, "[line %d] Error", token->line);

    if (token->type == TOKEN_EOF) {
        fprintf(stderr, " at end");
    } else if (token->type == TOKEN_ERROR) {
        // nothing
    } else {
        fprintf(stderr, " at '%.*s'", token->length, token->start);
    }
    fprintf(stderr, ": %s\n", message);
    parser.hadError = true;
}

static void consume(TokenType type, const char* message) {
    if (parser.current.type == type) {
        advance();
        return;
    }
    errorAtCurrent(message);
}

static void endCompiler() { emitReturn(); }

static void emitByte(uint8_t byte) {
    writeChunk(currentChunk(), byte, parser.previous.line);
}
static void emitReturn() { emitByte(OP_RETURN); }
static void emitBytes(uint8_t byte1, uint8_t byte2) {
    emitByte(byte1);
    emitByte(byte2);
}
