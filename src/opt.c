#include "opt.h"

CorkOpt *
corkopt_init(void)
{
    CorkOpt *co;

    if ((co = malloc(sizeof(CorkOpt))) == NULL)
        return NULL;

    co->args = corklist_create();
    return co;
}

void
corkopt_set_char(CorkOpt *co, const char *what)
{
    co->flag_char = what;
}

void
corkopt_fini(CorkOpt *co)
{ }

void
corkopt_help(CorkOpt *co)
{
    void *t;
    CorkOptElement *coe;

    CORKLIST_FOREACH(co->args, t)
    {
        coe = (CorkOptElement *)t;

        printf("Usage:\n");
        printf("%s or %s: %s\n", coe->short_opt,
                                 coe->long_opt,
                                 coe->help_text);
    }
}

void
corkopt_add(CorkOpt *co,
            int shortopt,
            const char *longopt,
            const char *helptext,
            void (*cb)(CorkOpt *co, const char *optarg),
            const int flags)
{
    CorkOptElement *coe;

    if ((coe = malloc(sizeof(CorkOptElement))) == NULL)
        return;

    coe->short_opt = shortopt;
    coe->long_opt  = longopt;
    coe->help_text = helptext;
    coe->flags     = flags;

    corklist_append(co->opts, coe);
    return;
}
