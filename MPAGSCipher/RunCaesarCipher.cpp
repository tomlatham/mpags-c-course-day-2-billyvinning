// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// For std::isalpha and std::isupper
#include <cctype>
#include<ProcessCommandLine.hpp>
#include<TransformChar.hpp>

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
	std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
	char elem{' '};
	std::string output{""};

	for(size_t i{0}; i < inputText.length(); i++)
	{
		for(size_t j{0}; j < alphabet.length(); j++)
		{
			if(inputText[i] == alphabet[j])
			{
				if(encrypt)
				{
					elem = alphabet[(j+key)%alphabet.length()];
				}
				else
				{
					elem = alphabet[(j-key)%alphabet.length()];
				}
			}
		}
		
		output+=elem;
	}
	return output;
	
}
