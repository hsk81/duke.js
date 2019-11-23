#include "module.h"
#include "io.h"

/**
 * TODO: implement same module resolution algorithm as for
 *       Node.js, incl. the checking for the `main` entry
 *       within the `package.json` file!
 * 
 *       Also consider relative path resolution w.r.t. the
 *       `parent-id` (and current working directory).
 */
duk_ret_t module_resolve(
    duk_context *ctx
) {
    const char *module_id = duk_get_string(ctx, 0);
    const char *parent_id = duk_get_string(ctx, 1);

    /* TODO: (parent-id, module-id) => path */
    duk_push_sprintf(ctx, "%s", module_id);
    return 1; /*nrets*/
}

duk_ret_t module_load(
    duk_context *ctx
) {
    duk_get_prop_string(ctx, 2, "filename");
    const char *file_path = duk_require_string(ctx, -1);

    auto file = io_ctor(file_path);
    if (!file->good()) {
        const char *module_id = duk_get_string(ctx, 0);
        duk_type_error(ctx, "Cannot find module '%s'", module_id);
        return 0; /*nrets*/
    }

    const std::string text = io_get(*file);
    duk_push_sprintf(ctx, "%s", text.c_str());
    io_dtor(file);

    return 1; /*nrets*/
}
