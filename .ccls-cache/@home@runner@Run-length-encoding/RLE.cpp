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

int main() {
    // Test Case 1: Repeating Characters Compression
    string input1 = "AAAABBBCCDAA";
    assert(RleCompress(input1) == "4A3B2C1D2A");
    assert(RleDecompress(RleCompress(input1)) == input1);

    // Test Case 2: Short Input Compression
    string input2 = "ABCDE";
    assert(RleCompress(input2) == "1A1B1C1D1E");
    assert(RleDecompress(RleCompress(input2)) == input2);

    // Test Case 3: No Repeating Characters Compression
    string input3 = "ABCDE";
    assert(RleCompress(input3) == "1A1B1C1D1E");
    assert(RleDecompress(RleCompress(input3)) == input3);

    // Test Case 4: Extremely Long Repeating Sequence Compression
    string input4 = "AAAAAAAAAA";
    assert(RleCompress(input4) == "10A");
    assert(RleDecompress(RleCompress(input4)) == input4);

    // Test Case 5: Boundary Case - Empty Input Compression
    string input5 = "";
    assert(RleCompress(input5) == "");
    assert(RleDecompress(RleCompress(input5)) == input5);

    // Test Case 6: Boundary Case - Single Character Input Compression
    string input6 = "A";
    assert(RleCompress(input6) == "1A");
    assert(RleDecompress(RleCompress(input6)) == input6);


    cout << "All test cases passed successfully!" << endl;
    cout << " " << endl;


    cout << "Input 1: " << input1 << endl;
    cout << "Output 1: " << RleCompress(input1) << endl; 
    cout << "Decompressed Output 1: " << RleDecompress(RleCompress(input1)) << endl; 
    cout << " " << endl;

    cout << "Input 2: " << input2 << endl;
    cout << "Output 2: " << RleCompress(input2) << endl;
    cout << "Decompressed Output 2: " << RleDecompress(RleCompress(input2)) << endl; 
    cout << " " << endl;

    cout << "Input 3: " << input3 << endl;
    cout << "Output 3: " << RleCompress(input3) << endl;
    cout << "Decompressed Output 3: " << RleDecompress(RleCompress(input3)) << endl; 
    cout << " " << endl;

    cout << "Input 4: " << input4 << endl;
    cout << "Output 4: " << RleCompress(input4) << endl;
    cout << "Decompressed Output 4: " << RleDecompress(RleCompress(input4)) << endl; 
    cout << " " << endl;

    cout << "Input 5: " << input5 << endl;
    cout << "Output 5: " << RleCompress(input5) << endl;
    cout << "Decompressed Output 5: " << RleDecompress(RleCompress(input5)) << endl; 
    cout << " " << endl;

    cout << "Input 6: " << input6 << endl;
    cout << "Output 6: " << RleCompress(input6) << endl;
    cout << "Decompressed Output 6: " << RleDecompress(RleCompress(input6)) << endl; 
    cout << " " << endl;

    // Measure compression ratio, compression speed, and memory usage
    string data = "AAAABBBCCCDDDDDDDDDDEEEEEEE";
    string compressed_data = RleCompress(data);

    // Measure compression ratio
    double compression_ratio = (double)data.size() / compressed_data.size();
    cout << "Compression Ratio: " << compression_ratio << endl;

    // Measure compression speed
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        RleCompress(data);
    }
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Compression Speed: " << elapsed.count() << " milliseconds" << endl;

    // Sample approach to measure memory usage
    cout << "Memory Usage: " << data.size() * sizeof(char) << " bytes" << endl;

    return 0;
}