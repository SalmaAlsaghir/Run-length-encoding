#include "rle.h"
#include <iostream>
#include <chrono>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace chrono;

void measureCompression(const string& data) {
    string compressed_data = RleCompress(data);
    double compression_ratio = static_cast<double>(data.size()) / compressed_data.size();
    cout << "Compression Ratio: " << compression_ratio << endl;

    auto start = steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        RleCompress(data);
    }
    auto end = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);
    cout << "Compression Speed: " << elapsed.count() << " microseconds" << endl;

    cout << "Memory Usage: " << data.size() * sizeof(char) << " bytes" << endl;
}

string generateRandomStringWithConsecutiveLetters(int length) {
    string input;
    srand(time(0)); // Seed random number generator
    for (int i = 0; i < length; ++i) {
        if (i > 0 && rand() % 2 == 0) {
            input += input.back(); // Insert consecutive letter
        } else {
            input += 'A' + rand() % 26; // Insert random character between 'A' and 'Z'
        }
    }
    return input;
}

  int main() {
      vector<string> inputs = {
          "AAAABBBCCDAA", // Test Case 1
          "ABCDE",        // Test Case 2
          "ABCDE",        // Test Case 3
          "AAAAAAAAAA",   // Test Case 4
          "",             // Test Case 5
          "A"             // Test Case 6
      };

      for (size_t i = 0; i < inputs.size(); ++i) {
          cout << "Test Case " << i + 1 << ":" << endl;
          cout << "Input: " << inputs[i] << endl;
          cout << "Output: " << RleCompress(inputs[i]) << endl;
          cout << "Decompressed Output: " << RleDecompress(RleCompress(inputs[i])) << endl;
          measureCompression(inputs[i]);
          cout << endl;
      }

      // Test with varying input sizes and levels of consecutive letters
      cout << "Testing with varying input sizes and levels of consecutive letters:" << endl;
      for (int size = 10; size <= 100000; size *= 10) {
          string test_input = generateRandomStringWithConsecutiveLetters(size);
          cout << "\nInput Size: " << size << endl;

          string compressed = RleCompress(test_input);
          cout << "Compressed Size: " << compressed.size() << endl;

          string decompressed = RleDecompress(compressed);
          cout << "Decompressed Matches: " << (decompressed == test_input ? "Yes" : "No") << endl;

          measureCompression(test_input);
      }

      return 0;
  }

