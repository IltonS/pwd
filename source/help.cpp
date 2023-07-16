#include <iostream>
#include "help.h"

void print_usage()
{
	std::cout << usage << std::endl;	
}

void print_help()
{
	std::cout << "Pwd - Simple password tools." << std::endl << std::endl;
	print_usage();
}