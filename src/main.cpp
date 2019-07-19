#include "main.h"
#include "dracula.h"
#include "io.h"

#include <assert.h>

int main(
    int argc, char *argv[]
) {
    duk_context *ctx = dracula_ctor();
    assert(ctx);

    if (argc > 1) {
        auto file = io_ctor(argv[1]);
        if (!file) {
            goto failure;
        }
        if (!dracula_run(ctx, {
            *file, std::string(argv[1])
        })) {
            io_dtor(file);
            goto failure;
        }
        io_dtor(file);
        goto success;
    }
    if (!dracula_run(ctx)) {
        goto failure;
    }

success:
    dracula_dtor(ctx);
    return EXIT_SUCCESS;
failure:
    dracula_dtor(ctx);
    return EXIT_FAILURE;
}
