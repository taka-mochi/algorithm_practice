#include <string>
#include <iostream>
#include <unordered_map>

bool check_duplicate_char_exists(const std::string &str)
{
	// O(N)
	std::unordered_map<char, bool> char_existence;
	for (char c : str)
	{
		if (char_existence.find(c) != char_existence.end())
		{
			// duplicated character found!
			return true;
		}
		char_existence[c] = true;
	}
	return false;
}

void main()
{
	std::string s = "abcdefg";
	bool required = false;
	std::cout << "check_dup(" << s << ") = " << check_duplicate_char_exists(s) << " (required = "<<required<<")" << std::endl;

	s = "abcaefg";
	required = true;
	std::cout << "check_dup(" << s << ") = " << check_duplicate_char_exists(s) << " (required = "<<required<<")" << std::endl;

	s = "";
	required = false;
	std::cout << "check_dup(" << s << ") = " << check_duplicate_char_exists(s) << " (required = "<<required<<")" << std::endl;
}
