#ifndef CORC_OPT_OPT_H
#define CORC_OPT_OPT_H

#include <libcorc/ds/list.h>
#include <libcorc/core/str.h>

typedef struct CorcOpt
{
    CorcList *args;
} CorcOpt;

#define CORCOPT_REQUIRED 0x00
#define CORCOPT_OPTIONAL 0x01

extern CorcOpt *corcopt_init(void);
extern void corcopt_fini(CorcOpt *co);
extern void corcopt_help(CorcOpt *co);
extern void corcopt_add(CorcOpt *co,
                        const int short_opt,
                        const char *long_opt,
                        const char *help_text,
                        void (*cb)(CorcOpt *co, CorcString *optarg),
                        const int flags);

extern void corcopt_parse(CorcOpt *co, int argc, char *argv[]);

#endif
