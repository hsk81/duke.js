/* 
 * File:   main.c
 * Author: hsk81
 */

#include <stdio.h>
#include "../lib/duktape-2.3.0/src/duktape.h"
#include "../lib/duktape-2.3.0/extras/console/duk_console.h"
#include "main.h"

extern ssize_t getline (char**, size_t*, FILE*);

size_t size;
char *line = NULL;

int main(int argc, char *argv[]) {
    duk_context *ctx = duk_create_heap_default();
    duk_console_init(ctx, 0 /*flags*/);
    if (getline(&line, &size, stdin) != -1) {
        duk_push_string(ctx, line);
        if (duk_peval(ctx) != 0) {
            printf(" ⫷ %s\n", duk_safe_to_string(ctx, -1));
        } else {
            printf(" ⪡ %s\n", duk_safe_to_string(ctx, -1));
        }
        duk_pop(ctx);
    }
    duk_destroy_heap(ctx);
    return EXIT_SUCCESS;
}
