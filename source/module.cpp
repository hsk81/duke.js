#include "module.h"
#include "io.h"

#include <filesystem>
namespace fs = std::filesystem;

duk_ret_t module_resolve(
    duk_context *ctx
) {
    const std::string module_id(duk_get_string(ctx, 0));
    const std::string parent_id(duk_get_string(ctx, 1));
    const std::string directory(
        parent_id.empty() ? std::string(".") : parent_id + "/.."
    );
    duk_push_sprintf(ctx, "%s",
        fs::weakly_canonical(directory + "/" + module_id).c_str()
    );
    return 1; /*nrets*/
}

duk_ret_t module_load(
    duk_context *ctx
) {
    duk_get_prop_string(ctx, 2, "filename");
    const std::string full_path(duk_require_string(ctx, -1));
    std::ifstream *file(io_ctor(full_path));
    if (!file->good()) {
        const std::string module_id(duk_get_string(ctx, 0));
        duk_type_error(ctx, "Cannot find module '%s'", module_id.c_str());
        io_dtor(file);
        return 0; /*nrets*/
    } else {
        const std::string text(io_get(*file));
        duk_push_sprintf(ctx, "%s", text.c_str());
        io_dtor(file);
        return 1; /*nrets*/
    }
}
