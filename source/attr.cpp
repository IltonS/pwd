#include <iostream>
#include "attr.h"
#include "version.h"

void attr_main(int argc, char** argv)
{
	if (argc == 1) {
		// Print an error message exit the program
		std::cerr << "No commands were informed." << std::endl;
		
		/* TODO (#1#): Print usage */
		
		exit(1);
	}
	
	// Loop through the arguments and parse them according to their flags
	for (int i = 1; i < argc; i++) {
		// Check if it is a flag for version
		if ( (strcmp(argv[i], "version") == 0) || (strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "--version") == 0) ) {
			print_version();			
			exit(0);
		}
		
		// Otherwise, it is an invalid flag
		// Print an error message
		std::cerr << "Invalid command: " << argv[i] << std::endl;
		
		/* TODO (#1#): Print usage */
		
		exit(1);
	}
}