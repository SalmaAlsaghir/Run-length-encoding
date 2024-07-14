#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <chrono>

using namespace std;

// Function definition for RLE compression
// Check if the input string is empty, return an empty string if so
// Initialize a stringstream to store the compressed output
// Initialize a count for the number of consecutive characters and the previous character
// Iterate over the input string starting from the second character because the first index has prev.
// Check if the current character is different from the previous character or if it has reached the end of the input string
// Append the count of consecutive characters followed by the character itself to the output
// Reset the count to 1 and update the previous character
// If the current character is the same as the previous character, increment the count
// Return the compressed output as a string

string RleCompress(const string &input) {

    if (input.empty()) 
      return "";


    std::stringstream output;


    int count = 1;
    char prev = input[0];


    for (size_t i = 1; i <= input.length(); ++i) {

        if (i == input.length() || input[i] != prev) {

            output << count << prev;

            count = 1;
            prev = input[i];
        } else {

            ++count;
        }
    }


    return output.str();
}

// Function definition for RLE decompression
// Initialize a stringstream to read the input string
// Initialize variables to store the current character and the number of repetitions
// Iterate over the input string
// Check if the current character is a digit
// If it is a digit, update the number of repetitions
// If it is not a digit, repeat the character based on the number of repetitions and append to the output
// Return the decompressed output as a string

string RleDecompress(const string &input) {
    std::stringstream input_stream(input);
    char current_char;
    int count = 0;
    std::stringstream output;

    while (input_stream >> current_char) {
        if (isdigit(current_char)) {
            count = count * 10 + (current_char - '0');
        } else {
            for (int i = 0; i < max(1, count); i++) {
                output << current_char;
            }
            count = 0;
        }
    }

    return output.str();
}

