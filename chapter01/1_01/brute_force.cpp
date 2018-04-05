#include <string>
#include <iostream>

bool check_duplicate_char_exists(const std::string &str)
{
	// O(len^2)
	size_t len = str.length();
	for (size_t i=0; i<len; i++)
	{
		for (size_t j=i+1; j<len; j++)
		{
			if (str[i] == str[j]) return true;
		}
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
