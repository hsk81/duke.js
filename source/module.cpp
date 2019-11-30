#include "module.h"
#include "io.h"

#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

duk_ret_t module_resolve(
    duk_context *ctx
) {
    std::string module(duk_get_string(ctx, 0));
    if (!std::regex_search(module, std::regex("\\.js$"))) {
        module.append(".js");
    };
    std::string parent(duk_get_string(ctx, 1));
    if (parent.empty()) {
        parent.append(".");
    } else {
        parent.append("/..");
    }
    const std::string path(fs::weakly_canonical(
        parent + "/" + module
    ));
    duk_push_sprintf(ctx, "%s", path.c_str());
    return 1; /*nrets*/
}

duk_ret_t module_load(
    duk_context *ctx
) {
    duk_get_prop_string(ctx, 2, "filename");
    const std::string path(duk_require_string(ctx, -1));
    std::ifstream *file(io_ctor(path, (std::ifstream*)nullptr));
    if (!file->good()) {
        const std::string module(duk_get_string(ctx, 0));
        duk_type_error(ctx, "Cannot find module '%s'", module.c_str());
        io_dtor(file);
        return 0; /*nrets*/
    } else {
        const std::string text(io_get(*file));
        duk_push_sprintf(ctx, "%s", text.c_str());
        io_dtor(file);
        return 1; /*nrets*/
    }
}
