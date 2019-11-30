#include "main.h"
#include "dracula.h"
#include "io.h"

#include <assert.h>

int main(
    int argc, char *argv[]
) {
    duk_context *ctx(dracula_ctor());
    assert(ctx);
    if (argc > 1) {
        const std::string path(argv[1]);
        std::ifstream *file(io_ctor(path, (std::ifstream*)nullptr));
        if (!file->good()) {
            io_dtor(file);
            goto failure;
        }
        if (!dracula_run(ctx, { *file, path })) {
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
