// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// Local includes
#include "ProcessCommandLine.hpp"


bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, bool& encrypt, std::string& key, std::string& inputFileName, std::string& outputFileName)
{
  typedef std::vector<std::string>::size_type size_type;

  const size_type nArgs {args.size()};
  
  bool pass = true;
  for (size_type i{1}; i < nArgs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-e" || args[i] == "-encrypt") {
      
      encrypt = true;

      if (i == nArgs-1) {
	std::cerr << "[error] -e requires a key argument" << std::endl;
	// set the return value to false to indicate failure
	pass = false;
      }
      else {
	key = args[i+1];
	i++;
      }
    }
    else if (args[i] == "-d" || args[i] == "-decrypt"){
      encrypt = false;

      if (i == nArgs-1) {
	std::cerr << "[error] -d requires a key argument" << std::endl;
	// set the return value to false to indicate failure
	pass = false;
      }
      else {
	key = args[i+1];
	i++;
      }
	
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument

      if (i == nArgs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	pass = false;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFileName = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nArgs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	pass = false;
      }
      else {
	// Got filename, so assign value and advance past it
	outputFileName = args[i+1];
	++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      pass = false;
    }
  }
	return pass;
}

