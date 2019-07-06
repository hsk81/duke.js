#include "dracula.h"
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

bool dracula_compile(
    duk_context *ctx, const IO &io
) {
    std::string text = io_get(io.istream);

    duk_uint_t flags = 0;
    flags |= DUK_COMPILE_EVAL;
    flags |= DUK_COMPILE_SHEBANG;

    duk_push_string(ctx, text.c_str());
    duk_push_string(ctx, "eval");

    if (duk_pcompile(ctx, flags) != 0) {
        io_put(io.estream, {
            " ⫷ ", duk_safe_to_string(ctx, -1), "\n"
        });
        return false;
    } else {
        return true;
    }
}

bool dracula_execute(
    duk_context *ctx, const IO &io
) {
    if (duk_pcall(ctx, 0) != 0) {
        io_put(io.estream, {
            " ⫷ ", duk_safe_to_string(ctx, -1), "\n"
        });
        duk_pop(ctx);
        return false;
    } else {
        io_put(io.ostream, {
            " ⪡ ", duk_safe_to_string(ctx, -1), "\n"
        });
        duk_pop(ctx);
        return true;
    }
}

bool dracula_run(
    duk_context *ctx, const IO &io
) {
    if (!dracula_compile(ctx, io)) {
        return false;
    }
    if (!dracula_execute(ctx, io)) {
        return false;
    }
    return true;
}
