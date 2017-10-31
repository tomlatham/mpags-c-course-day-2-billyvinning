#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include<ProcessCommandLine.hpp>
#include<TransformChar.hpp>
#include<cmath>

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
	std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
	char elem{' '};
	std::string output{""};

	for(size_t i{0}; i < inputText.length(); i++)
	{
		// Ignores anything but letters

		if(!std::isalpha(inputText[i]) || inputText[i] == ' ')
		{
			output+=inputText[i];
			continue;
		}

		// Read through input string 

		for(size_t j{0}; j < alphabet.length(); j++)
		{
			// Processes uppercase characters

			if(std::isupper(inputText[i]) && std::tolower(inputText[i]) == alphabet[j])
			{
				if(encrypt)
				{
					elem = std::toupper(alphabet[(j+key)%25]);
				}
				else
				{
					elem = std::toupper(alphabet[((j-key)+25)%25]);
				}
				
			}

			// Processes lowercase characters

			if(std::islower(inputText[i]) && inputText[i] == alphabet[j])
			{
				if(encrypt)
				{
					elem = alphabet[(j+key)%25];
				}
				else
				{
					elem = alphabet[((j-key)+25)%25];
				}
			}
		}
		
		output+=elem;
	}
	return output;
	
}
