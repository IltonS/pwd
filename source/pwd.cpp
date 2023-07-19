/*
 * pwd.cpp - Simple password tools
 *
 * Copyright (c) 2023 Ilton Sequeira
 * 
 * This work is licensed under the MIT License
 *
 * https://github.com/IltonS/pwd/blob/main/LICENSE
 *
 */
  
#include <iostream>
#include "version.h"
#include "help.h"
#include "generate.h"

int main(int argc, char** argv) {
	
	if (argc == 1) {
		// Print an error message exit the program
		std::cerr << "No commands were informed." << std::endl << std::endl;
		
		hlp::print_usage();
		
		exit(1);
	}
	
	// Loop through the arguments and parse them according to their flags
	for (int i = 1; i < argc; i++) {
		// Check if it is a flag for version
		if ( (strcmp(argv[i], "version") == 0) || (strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "--version") == 0) ) {
			ver::print_version();			
			exit(0);
		}
		
		// Check if it is a flag for help
		if ( (strcmp(argv[i], "help") == 0) || (strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0) ) {
			hlp::print_help();	
			exit(0);
		}
		
		// Check for generate command
		if (strcmp(argv[i], "generate") == 0) {
			gen::generate_main(argc, argv);
		}
		else {
			// Otherwise, it is an invalid flag
			std::cerr << "Invalid command: " << argv[i] << std::endl << std::endl;
			
			hlp::print_usage();
			
			exit(1);	
		}
	}
	
	return 0;
}