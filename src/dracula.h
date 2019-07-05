#ifndef DRACULA_H
#define DRACULA_H

#include "io.h"
#include "../lib/duktape-2.3.0/src/duktape.h"

duk_context* dracula_ctor(
    duk_context *ctx = nullptr) ;
duk_context* dracula_dtor(
    duk_context *ctx);

void dracula_compile(
    duk_context *ctx, const IO &io = standard_io);
void dracula_call(
    duk_context *ctx, const IO &io = standard_io);

#endif /* DRACULA_H */