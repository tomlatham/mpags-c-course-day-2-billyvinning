// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
// For std::isalpha and std::isupper
#include <cctype>
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

 
	// Process command line arguments - ignore zeroth element, as we know this to
	// be the program name and don't need to worry about it

	processCommandLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key, inputFile, outputFile);

	// Initialise variables for processing input text

	char inputChar {'x'};
	
	std::string inputText {""};

 	std::ifstream in_file{};
 	std::ofstream out_file{};

 	if (!inputFile.empty())
	{
		in_file.open(inputFile);
 	}
	if (!outputFile.empty())
	{
		out_file.open(outputFile);
	}

 	if(!inputFile.empty() && in_file.good())
	{
		while(in_file >> inputChar)
		{
			inputText += inputChar;
		}
  	}
  	else
  	{
  		while(std::cin >> inputChar)
  		{	
			inputText += inputChar;
  		}
	}
	
	in_file.close();

	std::stringstream sstream(key);
	size_t inKey;
	sstream >> inKey;

	inputText = runCaesarCipher(inputText, inKey, encrypt);
	out_file.open(outputFile);
 
	// Output the transliterated text
	// Warn that output file option not yet implemented

	if (!outputFile.empty() && out_file.good())
	{
		out_file << inputText;
	}
	else
	{
  		std::cout << inputText << std::endl;
	}
  
	return 0;
}

