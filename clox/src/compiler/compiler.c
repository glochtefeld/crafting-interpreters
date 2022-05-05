#include <stdio.h>
#include "common.h"
#include "compiler/compiler.h"
#include "scanner/scanner.h"

void compile(const char* source) {
    initScanner(source);

    // Temporary kickstart code
    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
            printf("%4d ", token.line);
            line = token.line;
        } else {
            printf("    | ");
        }
        printf ("%2d '%.*s'\n", token.type, token.length, token.start);

        if (token.type == TOKEN_EOF break;
    }
}
