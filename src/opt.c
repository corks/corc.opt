#include "opt.h"

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
corcopt_set_char(CorcOpt *co, const char *what)
{
    co->flag_char = what;
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

        printf("Usage:\n");
        printf("%s or %s: %s\n", coe->short_opt,
                                 coe->long_opt,
                                 coe->help_text);
    }
}

void
corcopt_add(CorcOpt *co,
            int shortopt,
            const char *longopt,
            const char *helptext,
            void (*cb)(CorcOpt *co, const char *optarg),
            const int flags)
{
    CorcOptElement *coe;

    if ((coe = malloc(sizeof(CorcOptElement))) == NULL)
        return;

    coe->short_opt = shortopt;
    coe->long_opt  = longopt;
    coe->help_text = helptext;
    coe->flags     = flags;

    corclist_append(co->opts, coe);
    return;
}
