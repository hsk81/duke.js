#include "dracula.h"
#include "io.h"

#include "../lib/duktape-2.3.0/src/duktape.h"
#include "../lib/duktape-2.3.0/extras/console/duk_console.h"

duk_context* dracula_ctor(
    duk_context *ctx
) {
    if (!ctx) {
        ctx = duk_create_heap_default();
    }
    if (ctx) {
        duk_console_init(ctx, DUK_CONSOLE_PROXY_WRAPPER /*flags*/);
    }
    return ctx ? ctx : nullptr;
}

duk_context* dracula_dtor(
    duk_context *ctx
) {
    if (ctx) {
        duk_destroy_heap(ctx);
    }
    return nullptr;
}

void dracula_compile(
    duk_context *ctx, const IO &io
) {
    std::string text = io_get(io.cin);

    duk_uint_t flags = 0;
    flags |= DUK_COMPILE_EVAL;
    flags |= DUK_COMPILE_SHEBANG;

    duk_push_string(ctx, text.c_str());
    duk_push_string(ctx, "eval");

    if (duk_pcompile(ctx, flags) != 0) {
        io_put(io.cerr, {
            " ⫷ ", duk_safe_to_string(ctx, -1), "\n"
        });
    }
}

void dracula_call(
    duk_context *ctx, const IO &io
) {
    if (duk_pcall(ctx, 0) != 0) {
        io_put(io.cerr, {
            " ⫷ ", duk_safe_to_string(ctx, -1), "\n"
        });
    } else {
        io_put(io.cout, {
            " ⪡ ", duk_safe_to_string(ctx, -1), "\n"
        });
    }
    duk_pop(ctx);
}
