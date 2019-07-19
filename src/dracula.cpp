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
    return ctx ? ctx : 0;
}

duk_context* dracula_dtor(
    duk_context *ctx
) {
    if (ctx) {
        duk_destroy_heap(ctx);
    }
    return 0;
}

bool dracula_compile(
    duk_context *ctx, const IO &io
) {
    const std::string text = io_get(io.istream);
    duk_push_string(ctx, text.c_str());

    if (io.iname.empty()) {
        duk_push_string(ctx, "stdin");
    } else {
        duk_push_string(ctx, io.iname.c_str());
    }

    duk_uint_t flags = 0;
    flags |= DUK_COMPILE_EVAL;
    flags |= DUK_COMPILE_SHEBANG;

    if (duk_pcompile(ctx, flags) != 0) {
        const std::string result(duk_safe_to_string(ctx, -1));
        io_put(io.estream, std::list<std::string>{
            result, std::string("\n")
        });
        return false;
    }
    return true;
}

bool dracula_execute(
    duk_context *ctx, const IO &io
) {
    if (duk_pcall(ctx, 0) != 0) {
        const bool has_stack = duk_is_error(ctx, -1);
        if (has_stack) duk_get_prop_string(ctx, -1, "stack");
        const std::string error(duk_safe_to_string(ctx, -1));
        io_put(io.estream, std::list<std::string>{
            error, std::string("\n")
        });
        if (has_stack) duk_pop(ctx);
        duk_pop(ctx);
        return false;
    }
    const std::string result(duk_safe_to_string(ctx, -1));
    if (!result.compare("undefined")) return true;
    io_put(io.ostream, std::list<std::string>{
        result, std::string("\n")
    });
    duk_pop(ctx);
    return true;
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
