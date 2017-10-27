// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"


std::string transformChar(const char in_char)
{
	std::string inputText{""};
    // Uppercase alphabetic characters
    if (std::isalpha(in_char)) {
      inputText += std::toupper(in_char);
    }

    // Transliterate digits to English words
    switch (in_char) {
      case '0':
	inputText += "ZERO";
	break;
      case '1':
	inputText += "ONE";
	break;
      case '2':
	inputText += "TWO";
	break;
      case '3':
	inputText += "THREE";
	break;
      case '4':
	inputText += "FOUR";
	break;
      case '5':
	inputText += "FIVE";
	break;
      case '6':
	inputText += "SIX";
	break;
      case '7':
	inputText += "SEVEN";
	break;
      case '8':
	inputText += "EIGHT";
	break;
      case '9':
	inputText += "NINE";
	break;
    }
	return inputText;
	
}

