#ifndef CORC_OPT_OPT_H
#define CORC_OPT_OPT_H

#include <stdio.h>
#include <libcorc/ds/list.h>
#include <libcorc/core/str.h>

#define CORCOPT_REQUIRED 0x00
#define CORCOPT_OPTIONAL 0x01

extern typedef struct CorcOpt
{
    CorcList *args;
} CorcOpt;

extern CorcOpt *corcopt_init(void);
extern void corcopt_fini(CorcOpt *co);
extern void corcopt_help(CorcOpt *co);
extern void corcopt_add(CorcOpt *co,
                        const char short_opt,
                        const char *long_opt,
                        const char *help_text,
                        void (*cb)(CorcOpt *co, CorcString *optarg),
                        const int flags);

extern void corcopt_parse(CorcOpt *co, int argc, char *argv[]);

#endif
