#ifndef HELP_H
#define HELP_H

#include <string>

const std::string usage = R"(Usage: pwd [-v | --version] [-h | --help]
           <command> [<args>]
           
Options:
   -h, --help    Show a help message and exit.
   -v, --version Show the program version and exit.
)";

// Print the program commands
void print_usage();

// Print a description and the program usage
void print_help();

#endif /* HELP_H */