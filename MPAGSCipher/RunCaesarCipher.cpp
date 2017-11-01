// Standard Library includes
#include <string>

// Local includes
#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
	// Create the alphabet container
	const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const size_t alphabetSize { alphabet.length() };

	// Create the output string
	std::string output{""};

	// Make sure that the key is in the range 0 - 25
	const size_t truncatedKey { key % alphabetSize };

	// Loop over the input text
	char elem {' '};
	for( const char inputChar : inputText )
	{
		// For each character in the input text, find the corresponding position in
		// the alphabet by using an indexed loop over the alphabet container
		for(size_t j{0}; j < alphabetSize; j++)
		{
			if(inputChar == alphabet[j])
			{
				// Apply the appropriate shift (depending on
				// whether we're encrypting or decrypting) and
				// determine the new character
				if(encrypt)
				{
					elem = alphabet[(j+truncatedKey)%alphabetSize];
				}
				else
				{
					elem = alphabet[(j-truncatedKey+alphabetSize)%alphabetSize];
				}

				// Can then break out of the loop over the alphabet
				break;
			}
		}

		// Add the new character to the output text
		output += elem;
	}
	return output;
}
