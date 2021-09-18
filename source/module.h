#ifndef MODULE_H
#define MODULE_H

#include "../library/duktape-2.6.0/source/duktape.h"

duk_ret_t module_resolve(
    duk_context *ctx
);
duk_ret_t module_load(
    duk_context *ctx
);

#endif /* MODULE_H */
