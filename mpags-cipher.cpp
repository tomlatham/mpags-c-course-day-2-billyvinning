// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile);
  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  std::ifstream in_file{};
  std::ofstream out_file{};
  if (!inputFile.empty()) {
	in_file.open(inputFile);
  }
  if (!outputFile.empty()){
	out_file.open(outputFile);
  }
  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  if(!inputFile.empty() && in_file.good()){
	while(in_file >> inputChar){
	inputText +=transformChar(inputChar);

	}
  }
  else
  {
  while(std::cin >> inputChar)
  {
	
	inputText += transformChar(inputChar);
    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
  }
}
	in_file.close();
	out_file.open(outputFile);
  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty() && out_file.good()) {
    out_file << inputText;
  }
  else{

  std::cout << inputText << std::endl;
}
  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;

}

