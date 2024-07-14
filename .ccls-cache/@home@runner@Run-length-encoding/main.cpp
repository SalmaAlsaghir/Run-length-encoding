#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

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

int main() {
    // Test Case 1: Repeating Characters
    string input1 = "AAAABBBCCDAA";
    assert(RleCompress(input1) == "4A3B2C1D2A");
  
    // Test Case 2: Short Input
    string input2 = "ABCDE";
    assert(RleCompress(input2) == "1A1B1C1D1E");
  
    // Test Case 3: No Repeating Characters
    string input3 = "ABCDE";
    assert(RleCompress(input3) == "1A1B1C1D1E");
  
    // Test Case 4: Extremely Long Repeating Sequence
    string input4 = "AAAAAAAAAA";
    assert(RleCompress(input4) == "10A");
  
    // Test Case 5: Boundary Case - Empty Input
    string input5 = "";
    assert(RleCompress(input5) == "");
  
    // Test Case 6: Boundary Case - Single Character Input
    string input6 = "A";
    assert(RleCompress(input6) == "1A");

  
    cout << "All test cases passed successfully!" << endl;
    cout << " " << endl;
   

    cout << "Input 1: " << input1 << endl;
    cout << "Output 1: " << RleCompress(input1) << endl; 
    cout << " " << endl;
    cout << "Input 2: " << input2 << endl;
    cout << "Output 2: " << RleCompress(input2) << endl;
    cout << " " << endl;
    cout << "Input 3: " << input3 << endl;
    cout << "Output 3: " << RleCompress(input3) << endl;
    cout << " " << endl;
    cout << "Input 4: " << input4 << endl;
    cout << "Output 4: " << RleCompress(input4) << endl;
    cout << " " << endl;
    cout << "Input 5: " << input5 << endl;
    cout << "Output 5: " << RleCompress(input5) << endl;
    cout << " " << endl;
    cout << "Input 6: " << input6 << endl;
    cout << "Output 6: " << RleCompress(input6) << endl;
    return 0;
}
