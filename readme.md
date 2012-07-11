ynys.opt
========

This software library is copyrighted under the X11 license; see the
`license.txt` file for more information.

ynys.opt is a component of the [libynys](http://github.com/corks/libynys)
project. You are free to use this component separately from the
libynys distribution.

Introduction
============

ynys.opt is a cross-platform command-line option parser. It works on
Windows and Unices (including OS X). It has the goal of providing a simple,
abstracted interface for option parsing.

ynys.opt operates based on rules. There are built-in rules which allow
ynys.opt to operate in the same manner as GNU's getopt(), or a similar
variation, or you can define your own arbitrary rule to use for parsing.

This allows for software developers to have much more flexibility and
control, but abstracted to the highest level while still being very
powerful. It does not use a switch-case scope for results, but rather uses
callbacks to make things easier to understand.

There are bindings available for the following languages:

* Python
* Ruby
* Perl
* .NET (C#)
* Java
* PHP
* Erlang

Example
=======

````
#include <libcork/opt.h>

void
set_config_file(CorkOpt *co, const char *optarg)
{
    printf("Config file is %s!\n", optarg);
}

int
main(int argc, char *argv[])
{
    // This allocates a CorkOpt instance.
    CorkOpt *co = corkopt_init();

    // This tells our CorkOpt instance to operate in a similar manner to
    // GNU's getopt().
    corkopt_set_rule(co, CORKOPT_GNU_GETOPT);

    // A typical option.
    corkopt_add(co,                                   // Our instance
                'c',                                  // Our short character representation of the long opt
                "config",                             // Our full character representation of the opt
                "Specify configuration file to use.", // Our help text
                set_config_file,                      // Function to call when this opt has been called
                CORKOPT_MANDATORY);                   // This option is required by the program.

    // Now parse the arguments.
    corkopt_parse(co, argc, argv);

    // By this time, all is done. Destroy the option parser.
    corkopt_fini(co);

    // Now return a successful execution to the operating system.
    return EXIT_SUCCESS;
}
````
