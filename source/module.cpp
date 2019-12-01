#include "module.h"
#include "base64.h"
#include "io.h"

#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

duk_ret_t module_resolve(
    duk_context *ctx
) {
    std::string module(duk_get_string(ctx, 0));
    if (std::regex_search(module, std::regex("^data:text/plain;base64,"))) {
        duk_push_string(ctx, module.c_str());
        return 1; /*nrets*/
    };
    if (!std::regex_search(module, std::regex("\\.js$"))) {
        module.append(".js");
    };
    std::string parent(duk_get_string(ctx, 1));
    if (parent.empty()) {
        if (!fs::path(module).is_absolute()) {
            parent.append("./");
        }
    } else {
        parent.append("/../");
    }
    duk_push_sprintf(ctx, "%s",
        fs::weakly_canonical(parent + module).c_str()
    );
    return 1; /*nrets*/
}

duk_ret_t module_load(
    duk_context *ctx
) {
    duk_get_prop_string(ctx, 2, "filename");
    const std::string path(duk_require_string(ctx, -1));
    if (std::regex_search(path, std::regex("^data:text/plain;base64,"))) {
        const std::string text(b64_decode(path.substr(23)));
        duk_push_string(ctx, text.c_str());
        return 1; /*nrets*/
    }
    std::ifstream *file(io_ctor(path, (std::ifstream*)nullptr));
    if (!file->good()) {
        const std::string module(duk_get_string(ctx, 0));
        duk_type_error(ctx, "Cannot find module '%s'", module.c_str());
        io_dtor(file);
        return 0; /*nrets*/
    } else {
        const std::string text(io_get(*file));
        duk_push_string(ctx, text.c_str());
        io_dtor(file);
        return 1; /*nrets*/
    }
}
