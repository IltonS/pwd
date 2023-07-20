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
#include "strength.h"

int main(int argc, char** argv) {
	
	if (argc == 1) {
		// Print an error message exit the program
		std::cerr << "No commands were informed." << std::endl << std::endl;
		
		hlp::print_usage();
		
		exit(1);
	}
	
	// Check if it is a flag for version
	if ( (strcmp(argv[1], "version") == 0) || (strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0) ) {
		ver::print_version();			
		exit(0);
	}
	
	// Check if it is a flag for help
	if ( (strcmp(argv[1], "help") == 0) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0) ) {
		hlp::print_help();	
		exit(0);
	}
	
	// Check for generate command
	if (strcmp(argv[1], "generate") == 0) {
		gen::generate_main(argc, argv);
	}
	
	// Check for determine strength command
	if (strcmp(argv[1], "strength") == 0) {
		stgh::strength_main(argc, argv);
	}
	
	// Otherwise, it is an invalid flag
	std::cerr << "Invalid command: " << argv[1] << std::endl << std::endl;
	
	hlp::print_usage();
	
	exit(1);
	
	return 0;
}