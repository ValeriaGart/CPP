#include <iostream>

int main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory addresses:" << std::endl;
	std::cout << "★Original string:\t\t" << &str << std::endl;
	std::cout << "★Pointer to the string:\t\t" << stringPTR << std::endl;
	std::cout << "★Reference to the string:\t" << &stringREF << std::endl;

	std::cout << "\nThe values:" << std::endl;
	std::cout << "★Original string:\t\t" << str << std::endl;
	std::cout << "★Pointer to the string:\t\t" << *stringPTR << std::endl;
	std::cout << "★Reference to the string:\t" << stringREF << std::endl;
	return (0);
}