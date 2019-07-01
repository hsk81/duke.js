#include "main.h"
#include "dracula.h"

#include <assert.h>

int main(
    int argc, char *argv[]
) {
    duk_context *ctx = dracula_ctor();
    assert(ctx);

    dracula_compile(ctx);
    dracula_call(ctx);

    ctx = dracula_dtor(ctx);
    assert(!ctx);

    return EXIT_SUCCESS;
}
