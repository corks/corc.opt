#include "opt.h"

static typedef struct CorcOptElement
{
    int short_opt;
    CorkString *long_opt;
    CorkString *help_opt;
    int flags;
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
{ }

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
            const int short_opt,
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
    coe->flags     = flags;

    corclist_append(co->opts, coe);
    return true;
}
