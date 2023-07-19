#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "generate.h"
#include "help.h"

int  gen::password_length = 0;
bool gen::use_upper = false;
bool gen::use_digit = false;
bool gen::use_lower = true;
bool gen::use_special = false;

bool gen::is_digit(char c) {
	return c >= '0' && c <= '9';
}

bool gen::is_upper(char c) {
	return c >= 'A' && c <= 'Z';
}

bool gen::is_lower(char c) {
	return c >= 'a' && c <= 'z';
}


bool gen::is_special(char c) {
	return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '=' || c == '+';
}

char gen::random_char() {
	// Define the possible characters
	const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
	 
	// Get the size of the array
	int size = sizeof(chars) - 1;
	 
	// Return a random character from the array
	return chars[rand() % size];
}

std::string gen::random_password() {
	// Initialize an empty string
	std::string password = "";
	
	// Initialize some flags to check the criteria
	bool has_digit = false;
	bool has_upper = false;
	bool has_lower = false;
	bool has_special = false;
	
	// Initialize a variable to store the previous character
	char prev = '\0';
	
	// Loop for the given length
	for (int i = 0; i < password_length; i++) {
		// Generate a random character
	 	char c = random_char();
	 
	 	// Check if it is equal to the previous character
	 	if (c == prev) {
	 		// Try again with a different character
	 		i--;
	 		continue;
		}
	
		// Check if it matches the parameters
		if (!use_digit && is_digit(c)) {
			// Try again with a different character
			i--;
			continue;
		}
		
		if (!use_upper && is_upper(c)) {
			// Try again with a different character
			i--;
			continue;
		}
		
		if (!use_lower && is_lower(c)) {
			// Try again with a different character
			i--;
			continue;
		}
		
		if (!use_special && is_special(c)) {
			// Try again with a different character
			i--;
			continue;
		}
		
		// Append it to the password
		password += c;
	
		// Update the flags according to the character
		if (is_digit(c)) {
			has_digit = true;
		}
		
		if (is_upper(c)) {
			has_upper = true;
		}
		
		if (is_lower(c)) {
			has_lower = true;
		}
		
		if (is_special(c)) {
			has_special = true;
		}
		
		// Update the previous character
		prev = c;
	} // for
	
	// Check if the password meets all the criteria
	if ( (!use_digit || (use_digit && has_digit)) &&
		 (!use_upper || (use_upper && has_upper)) &&
		 (!use_lower || (use_lower && has_lower)) &&
		 (!use_special || (use_special && has_special))
	) {
		// Return the password
		return password;
	} else {
		// Try again with a new password
		return random_password();
	}
}

void gen::generate_main(int argc, char** argv)
{	
	// Initialize the random seed
	srand(time(0));
	
	if (strcmp(argv[2], "--fort-knox") == 0) {
		password_length = 16;
		use_digit = true;
		use_upper = true;
		use_special = true;
	} else if ( (argc >=4) && ( (strcmp(argv[2], "-l") == 0) || (strcmp(argv[2], "--length") == 0) ) ) { // Ceck if the length param was informed
		// Convert it to an integer and store it in length variable
		password_length = atoi(argv[3]);
		
		// Check if the length is between 4 and 16
		if (!(password_length >= MIN_PASSWORD_LENGTH && password_length <= MAX_PASSWORD_LENGTH)) {
			// Print an error message
			std::cerr << "Invalid password length. It must be between " << MIN_PASSWORD_LENGTH << " and " << MAX_PASSWORD_LENGTH << std::endl;
			exit(1);
		}
		
		// Loop through the arguments and parse them according to their flags
		for (int i = 4; i < argc; i++) {
			if ((strcmp(argv[i], "-d") == 0) || (strcmp(argv[i], "--digits") == 0)){ // Check if it is a flag for digit
				// Set the useDigit variable to true
				use_digit = true;
			}
			else if ((strcmp(argv[i], "-u") == 0) || (strcmp(argv[i], "--upper") == 0)) { // Check if it is a flag for upper
				// Set the useUpper variable to true
				use_upper = true;
			}
			else if ((strcmp(argv[i], "-s") == 0) || (strcmp(argv[i], "--special") == 0)) { // Check if it is a flag for special
				// Set the useSpecial variable to true
				use_special = true;
			}
			else if (argv[i][0] == '-') { // Check if it is a combined flag for digit, upper, lower and special
				// Loop through the characters of the flag
				for (int j = 1; argv[i][j] != '\0'; j++) {
					// Check which option it matches and set the corresponding variable to true
					switch (argv[i][j]) {
						case 'd':
							use_digit = true;
							break;
						case 'u':
							use_upper = true;
							break;
						case 's':
							use_special = true;
							break;
						default:
							// Otherwise, it is an invalid option
							std::cerr << "Invalid option: " << argv[i] << std::endl << std::endl;	
							hlp::print_usage();
							exit(1);
					}
				} // for
			}
			else {
				// Otherwise, it is an invalid flag
				std::cerr << "Invalid option: " << argv[i] << std::endl << std::endl;	
				hlp::print_usage();
				exit(1);
			}	
		} // for
	}
	else
	{
		// Print an error message and exit the program
		std::cerr << "Missing argument." << std::endl << std::endl;
		hlp::print_usage();
		exit(1);
	}
	
	std::cout << random_password() << std::endl;
	exit(0);
}