#ifndef HELP_H
#define HELP_H

#include <string>

namespace hlp {
	
const std::string usage = R"(Usage: pwd [-v | --version] [-h | --help]
           <command> [<args>]
       
Options:
   -h, --help    Show a help message and exit.
   -v, --version Show the program version and exit.

Commands:
   generate -l <length> [ [-u] [-d] [-s] | -[u][d][s] ]
            --fort-knox
			 
   -l, --length  Use this option to specify the length of the password.
   -u, --upper   Include uppercase letters in the password.
   -d, --digits  Include digits in the password.
   -s, --special Include special characters in the password.

   <length> Specify the length of the password, between 4 and 16.
   
   --fort-knox Shortcut for -l 16 -uds
   
   
   strength <password>
   
   <passowd> A password to determine how strong it is.
)";

// Print the program commands
void print_usage();

// Print a description and the program usage
void print_help();
	

} // namespace

#endif /* HELP_H */