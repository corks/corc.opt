///
/// @file
/// @author Michael Rodriguez <adeo2232@gmail.com>
/// @version 1.0
///
/// @section LICENSE
///
/// Copyright (c) 2012 Corks Development Group
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the
/// "Software"), to deal in the Software without restriction, including
/// without limitation the rights to use, copy, modify, merge, publish,
/// distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to
/// the following conditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
/// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
/// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
/// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
/// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
/// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
/// @section DESCRIPTION
///
/// This file contains the implementation of the API.

#include "opt.h"

static typedef struct CorcOptElement
{
    char short_opt;
    int flags;
    CorcString *long_opt, *help_text;
} CorcOptElement;

CorcOpt *
corcopt_init(void)
{
    CorcOpt *co;

    if ((co = malloc(sizeof(CorcOpt))) == NULL)
        return NULL;

    co->args = corclist_create();
    return co;
}

void
corcopt_fini(CorcOpt *co)
{
    CorcOptElement *coe;
    void *t;

    CORCLIST_FOREACH(co->args, t)
    {
        coe = (CorcOptElement *)t;
        free(coe);
    }

    corclist_fini(co->args);
    free(co);
}

void
corcopt_help(CorcOpt *co)
{
    void *t;
    CorcOptElement *coe;

    CORCLIST_FOREACH(co->args, t)
    {
        coe = (CorcOptElement *)t;

        printf("Usage: %s\n");
        printf("%s or %s: %s\n", coe->short_opt->string,
                                 coe->long_opt->string,
                                 coe->help_text->string);
    }
}

bool
corcopt_add(CorcOpt *co,
            const char short_opt,
            const char *long_opt,
            const char *help_text,
            void (*cb)(CorcOpt *co, CorcString *optarg),
            const int flags)
{
    CorcOptElement *coe;

    if ((coe = malloc(sizeof(CorcOptElement))) == NULL)
        return false;

    coe->short_opt = short_opt;
    coe->long_opt  = corcstr(long_opt);
    coe->help_text = corcstr(help_text);
    coe->cb        = cb;
    coe->flags     = flags;

    corclist_append(co->opts, coe);
    return true;
}

void
corcopt_parse(CorcOpt *co, int argc, char *argv[])
{
    CorcOptElement *coe;
    CorcString *optarg;
    void *t;

    CORCLIST_FOREACH(co->args, t)
    {
        coe = (CorkOptElement *)t;
    }
}
