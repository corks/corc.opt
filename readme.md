corc.opt
========

This software library is copyrighted under the X11 license; see the
`license.txt` file for more information.

corc.opt is a component of the [libcorc](http://github.com/corks/libcorc)
project. You are free to use this component separately from the
libcorc distribution.

Introduction
============

corc.opt is a cross-platform command-line option parser. It works on
Windows and Unices (including OS X). It has the goal of providing a simple,
abstracted interface for option parsing.

corc.opt operates based on rules. There are built-in rules which allow
corc.opt to operate in the same manner as GNU's getopt(), or you can
define your own arbitrary rule to use for parsing.

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
#include <libcorc/opt.h>

void
set_config_file(CorcOpt *co, const char *optarg)
{
    printf("Config file is %s!\n", optarg);
}

int
main(int argc, char *argv[])
{
    // This allocates a CorcOpt instance.
    CorcOpt *co = corcopt_init();

    // This tells our CorcOpt instance to operate in a similar manner to
    // GNU's getopt().
    corcopt_set_rule(co, CORCOPT_GNU_GETOPT);

    // A typical option.
    corcopt_add(co,                                   // Our instance
                'c',                                  // Our short character representation of the long opt
                "config",                             // Our full character representation of the opt
                "Specify configuration file to use.", // Our help text
                set_config_file,                      // Function to call when this opt has been called
                CORCOPT_MANDATORY);                   // This option is required by the program.

    // Now parse the arguments.
    corcopt_parse(co, argc, argv);

    // By this time, all is done. Destroy the option parser.
    corcopt_fini(co);

    // Now return a successful execution to the operating system.
    return EXIT_SUCCESS;
}
````

Further examples can be see on the wiki.

Changelog
=========

1.0: Initial release.

Credits
=======

This software was written by the libcorc development team and contributors.
