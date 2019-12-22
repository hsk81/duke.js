#include "module.h"
#include "io.h"

#include <filesystem>
#include <stdio.h>
#include <regex>

namespace fs = std::filesystem;
static const std::string dev_stdin(
    fs::path("/dev/stdin").lexically_normal().string()
);
static const std::regex ext_json(
    "\\.json$", std::regex::icase
);
static const std::regex ext_js(
    "\\.js$", std::regex::icase
);

duk_ret_t module_resolve(
    duk_context *ctx
) {
    std::string module(
        fs::path(duk_get_string(ctx, 0)).lexically_normal().string()
    );
    if (module == dev_stdin) {
        duk_push_string(ctx, module.c_str());
        return 1; /*nrets*/
    }
    if (!std::regex_search(module, ext_json) &&
        !std::regex_search(module, ext_js)
    ) {
        module.append(".js");
    };
    std::string parent(
        fs::path(duk_get_string(ctx, 1)).lexically_normal().string()
    );
    if (parent.empty()) {
        if (!fs::path(module).is_absolute()) {
            parent.append("./");
        }
    } else {
        if (parent != dev_stdin) {
            if (!fs::path(module).is_absolute()) {
                parent.append("/../");
            } else {
                parent.clear();
            }
        } else {
            parent.clear();
        }
    }
    const std::string path(
        fs::weakly_canonical(parent + module).string()
    );
    duk_push_string(ctx, path.c_str());
    return 1; /*nrets*/
}

duk_ret_t module_load(
    duk_context *ctx
) {
    duk_get_prop_string(ctx, 2, "filename");
    const std::string path(duk_require_string(ctx, -1));
    std::ifstream *file(io_ctor(path, path == dev_stdin
        ? (std::ifstream*)&standard_io.istream
        : (std::ifstream*)nullptr)
    );
    if (!file->good()) {
        const std::string module(duk_get_string(ctx, 0));
        duk_type_error(ctx, "Cannot find module '%s'", module.c_str());
        if (path != dev_stdin) {
            io_dtor(file);
        }
        return 0; /*nrets*/
    }
    const std::string text(io_get(*file));
    if (std::regex_search(path, ext_json)) {
        duk_push_sprintf(ctx, "module.exports = %s", text.c_str());
    } else {
        duk_push_string(ctx, text.c_str());
    }
    if (path != dev_stdin) {
        io_dtor(file);
    }
    return 1; /*nrets*/
}
