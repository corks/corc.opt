#ifndef CORK_OPT_OPT_H
#define CORK_OPT_OPT_H

#include <libcork/ds.h>

typedef struct CorkOpt
{
    CorkList *args;
} CorkOpt;

extern CorkOpt *corkopt_init(void);
extern void corkopt_fini(CorkOpt *co);
extern void corkopt_help(CorkOpt *co);
extern void corkopt_add(CorkOpt *co,
                        const int shortopt,
                        const char *longopt,
                        const char *helptext,
                        void (*cb)(CorkOpt *co, const char *optarg),
                        const int flags);

extern void corkopt_parse(CorkOpt *co, int argc, char *argv[]);

#endif
