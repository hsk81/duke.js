#include "main.h"
#include "dracula.h"
#include "io.h"

#include <assert.h>
#include <filesystem>
namespace fs = std::filesystem;

int main(
    int argc, char *argv[]
) {
    duk_context *ctx(dracula_ctor());
    assert(ctx);
    if (argc > 1) {
        const std::string path(argv[1]);
        std::ifstream *file(io_ctor(path));
        if (!file->good()) {
            io_dtor(file);
            goto failure;
        }
        fs::current_path(
            fs::weakly_canonical(path + "/..")
        );
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
