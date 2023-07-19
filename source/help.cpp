#include <iostream>
#include "help.h"

void hlp::print_usage()
{
	std::cout << usage << std::endl;	
}

void hlp::print_help()
{
	std::cout << "Pwd - Simple password tools." << std::endl << std::endl;
	print_usage();
}