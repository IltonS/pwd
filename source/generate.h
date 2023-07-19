#ifndef GENERATE_H
#define GENERATE_H

#include <string>

namespace gen {
	
const int MIN_PASSWORD_LENGTH = 4;
const int MAX_PASSWORD_LENGTH = 16;

extern int  password_length;
extern bool use_digit;
extern bool use_upper;
extern bool use_lower;
extern bool use_special;


// A function to check if a character is a digit
bool is_digit(char c);


// A function to check if a character is an uppercase letter
bool is_upper(char c);

// A function to check if a character is a lowercase letter
bool is_lower(char c);

// A function to check if a character is a special character
bool is_special(char c);


// A function to generate a random character
char random_char();


// A function to generate a random password of a given length with some criteria and no consecutive characters
std::string random_password();


// Generate module entry point
void generate_main(int argc, char** argv);	

} // namespace

#endif /* GENERATE_H */