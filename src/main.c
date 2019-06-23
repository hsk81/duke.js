/* 
 * File:   main.c
 * Author: hsk81
 */

#include <stdio.h>
#include "duktape.h"
#include "main.h"

extern ssize_t getline (char**, size_t*, FILE*);

size_t size;
char *line = NULL;

static duk_ret_t native_log(duk_context *ctx) {
    printf(" ⪢ %s\n", duk_safe_to_string(ctx, -1));
    return 0;
}

int main(int argc, char *argv[]) {
    duk_context *ctx = duk_create_heap_default();
    duk_push_c_function(ctx, native_log, 1 /*nargs*/);
    duk_put_global_string(ctx, "log");
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
