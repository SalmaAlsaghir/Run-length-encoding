# Run-Length Encoding (RLE) Compression System

Welcome to the Run-Length Encoding (RLE) Compression System! This system allows you to compress and decompress text using the RLE algorithm, which is efficient for strings with consecutive repeated characters.

## Table of Contents

1. [Overview](#overview)
2. [Classes and Functions](#classes-and-functions)
3. [Usage](#usage)
4. [Performance Measurement](#performance-measurement)
5. [File Structure](#file-structure)
6. [Error Handling](#error-handling)

## Overview

The RLE Compression System includes functions for compressing and decompressing strings using Run-Length Encoding. It also includes performance measurement functions to evaluate the compression ratio, speed, and memory usage.

## Classes and Functions

### RLE Compression and Decompression

#### Functions

- **RleCompress(const string& input)**: Compresses the input string using RLE.
  - Parameters: `const string& input` - The input string to be compressed.
  - Returns: `string` - The compressed string.

- **RleDecompress(const string& input)**: Decompresses the input string using RLE.
  - Parameters: `const string& input` - The compressed string to be decompressed.
  - Returns: `string` - The decompressed string.

### Performance Measurement

#### Functions

- **measureCompression(const string& data)**: Measures the compression ratio, speed, and memory usage for the given input data.
  - Parameters: `const string& data` - The input string to be measured.

### Utility Functions

- **generateRandomStringWithConsecutiveLetters(int length)**: Generates a random string with consecutive letters for testing purposes.
  - Parameters: `int length` - The length of the generated string.
  - Returns: `string` - The generated random string.

## Usage

1. **Compile the Program**: Compile the program using a C++ compiler.
    ```sh
    g++ -o RLECompressor main.cpp rle.cpp
    ```

2. **Run the Program**: Execute the compiled program.
    ```sh
    ./RLECompressor
    ```

3. **Main Function**: The main function will automatically run tests on predefined input strings and display the results for encoding, decoding, and performance measurements.

## Performance Measurement

The performance of the RLE Compression System is measured using the `measureCompression` function, which reports:

- **Compression Ratio**: The ratio of the size of the original text to the size of the compressed text.
- **Compression Speed**: The time taken to compress the input text, measured in microseconds.
- **Memory Usage**: The approximate memory usage for storing the input and compressed text.

Performance is tested with varying input sizes and levels of consecutive letters to demonstrate scalability.

## File Structure

- **rle.h**: Header file containing the declarations of the RLE compression and decompression functions.
- **rle.cpp**: Implementation file containing the definitions of the RLE compression and decompression functions.
- **main.cpp**: Main file containing the `main` function and performance measurement tests.

## Error Handling

- Input validation is performed for the compression and decompression processes to ensure valid text.
- Errors in the input string are managed by checking for empty strings and ensuring valid character processing.

Enjoy using the Run-Length Encoding (RLE) Compression System for efficient text compression and decompression!