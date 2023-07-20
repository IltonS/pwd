#include <iostream>
#include <string>
#include "strength.h"
#include "generate.h"
#include "help.h"

bool stgh::contains_common_words(std::string str)
{
	return false;
}

int stgh::calculate_score(std::string password)
{
	// Initialize some variables to store the criteria counts
  	int digit_count = 0;
  	int upper_count = 0;
  	int lower_count = 0;
  	int special_count = 0;

  	// Loop through the characters of the password and update the counts accordingly
  	for (char c : password) {
    	if (gen::is_digit(c)) {
      		digit_count++;
    	}
    
		if (gen::is_upper(c)) {
      		upper_count++;
    	}
    
		if (gen::is_lower(c)) {
      		lower_count++;
    	}
    
		if (gen::is_special(c)) {
      		special_count++;
    	}
  	};

  	// Return the total score based on the length and criteria counts
  	return password.length() + digit_count * 2 + upper_count * 3 + lower_count * 2 + special_count * 4;
}

std::string stgh::determine_strength(std::string password)
{
	// Calculate the score of the password
	int score = calculate_score(password);
  
	// Check if the password contains any common words
	if (contains_common_words(password)) {
	    /*
		// Subtract 10 points for each common word in the password
		int common_word_count = count_words(password); // A function that counts the number of words in a string
		score -= common_word_count * 10;
	    
		// Make sure the score is not negative
		if (score < 0) {
	      score = 0;
	    }
	    */
	}
	  
	// Return a string indicating the strength of the password based on the score
	if (score >= 40) {
		return "Very Strong";
	} else if (score >= 30) {
		return "Strong";
	} else if (score >= 20) {
		return "Moderate";
	} else if (score >= 10) {
		return "Weak";
	} else {
		return "Very Weak";
	}
}

void stgh::strength_main(int argc, char** argv)
{
	if (argc <= 2) {
		std::cerr << "Invalid password." << std::endl << std::endl;
		hlp::print_usage();
		
		exit(1);		
	}
	
	std::cout << determine_strength(argv[2]) << std::endl;
	exit(0);
}