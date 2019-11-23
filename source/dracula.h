#ifndef DRACULA_H
#define DRACULA_H

#include "io.h"
#include "../library/duktape-2.4.0/source/duktape.h"

duk_context* dracula_ctor(
    duk_context *ctx = 0) ;
duk_context* dracula_dtor(
    duk_context *ctx);

bool dracula_compile(
    duk_context *ctx, const IO &io = standard_io);
bool dracula_execute(
    duk_context *ctx, const IO &io = standard_io);
bool dracula_run(
    duk_context *ctx, const IO &io = standard_io);

#endif /* DRACULA_H */
