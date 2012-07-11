#ifndef CORK_OPT_OPT_H
#define CORK_OPT_OPT_H

#include <libcork/ds.h>

typedef struct CorkOpt
{
    // ../
} CorkOpt;

CorkOpt *corkopt_init(int argc, char *argv[]);
void corkopt_fini(CorkOpt *co);

#endif
