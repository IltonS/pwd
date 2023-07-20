#ifndef STRENGTH_H
#define STRENGTH_H

#include <string>

namespace stgh {

// A function that checks if a string contains any common words
bool contains_common_words(std::string str);

// A function that calculates the score of a password based on its length and characters
int calculate_score(std::string password);

// A function that determines the strength of a password based on its score and common words
std::string determine_strength(std::string password);

// Strength module entry point
void strength_main(int argc, char** argv);

} // namespace

#endif /* HELP_H */