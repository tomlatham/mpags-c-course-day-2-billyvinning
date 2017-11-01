// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"
// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
	// Convert the command-line arguments into a more easily usable form
	const std::vector<std::string> cmdLineArgs {argv, argv+argc};

	// Options that might be set by the command-line arguments
	bool helpRequested {false};
	bool versionRequested {false};
	bool encrypt {false};
	std::string key {0};
	std::string inputFile {""};
 	std::string outputFile {""};

 
	// Process command line arguments
	bool cmdLineStatus { processCommandLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key, inputFile, outputFile) };
	// Any failure in the argument processing means we can't continue
	// Use a non-zero return value to indicate failure
	if( !cmdLineStatus ) {
		return 1;
	}

	// Handle help, if requested
	if (helpRequested) {
		// Line splitting for readability
		std::cout
			<< "Usage: mpags-cipher [-i <file>] [-o <file>] [-k <key>] [--encrypt/--decrypt]\n\n"
			<< "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
			<< "Available options:\n\n"
			<< "  -h|--help        Print this help message and exit\n\n"
			<< "  --version        Print version information\n\n"
			<< "  -i FILE          Read text to be processed from FILE\n"
			<< "                   Stdin will be used if not supplied\n\n"
			<< "  -o FILE          Write processed text to FILE\n"
			<< "                   Stdout will be used if not supplied\n\n"
			<< "  -e KEY           Specify encryption mode with the cipher key KEY\n\n"
			<< "  -d KEY           Specify decryption mode with the cipher key KEY\n\n";
		// Help requires no further action, so return from main,
		// with 0 used to indicate success
		return 0;
	}

	// Handle version, if requested
	if (versionRequested) {
		std::cout << "0.2.0" << std::endl;
		// Like help, requires no further action, so return from main,
		// with 0 used to indicate success
		return 0;
	}

	// Initialise variables for processing input text

	char inputChar {'x'};
	
	std::string inputText {""};

 	std::ifstream in_file{};
 	std::ofstream out_file{};

 	if (!inputFile.empty())
	{
		in_file.open(inputFile);

		if ( ! in_file.good() ) {
			std::cerr << "[error] problem opening file " << inputFile << " for reading" << std::endl;
		}
 	}

 	if(!inputFile.empty() && in_file.good())
	{
		while(in_file >> inputChar)
		{
			inputText += transformChar(inputChar);
		}
  	}
  	else
  	{
  		while(std::cin >> inputChar)
  		{	
			inputText += transformChar(inputChar);
  		}
	}
	
	in_file.close();
	
	// Converts key string to size_t to be input into runCaesarCipher

	std::stringstream sstream(key);
	size_t inKey{0};
	sstream >> inKey;
	if ( sstream.bad() || sstream.fail() ) {
		std::cerr << "[error] cannot convert supplied key to unsigned integer" << std::endl;
		return 1;
	}

	// Encrypts or decrypts string

	inputText = runCaesarCipher(inputText, inKey, encrypt);
 
	// Output the transliterated text
	// Warn that output file option not yet implemented

	if (!outputFile.empty()) {
		out_file.open(outputFile);
		if (out_file.good())
		{
			out_file << inputText << std::endl;;
			out_file.close();
			//std::cout << inputText << std::endl;
		}
		else
		{
			std::cerr << "[error] problem opening file " << outputFile << " for writing" << std::endl;
			std::cout << inputText << std::endl;
		}
	} else {
		std::cout << inputText << std::endl;
	}
  
	return 0;
}

