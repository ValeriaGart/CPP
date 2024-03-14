#include "./incl/phonebook_class.hpp"
#include <iostream>

int main()
{
	PhoneBook	phone_book;
	std::string	read_line = "";

	phone_book.ft_instructions();
	std::cout << "What can I do for you? 👀" << std::endl;
	while (read_line.compare("EXIT") != 0)
	{
		if (read_line.compare("ADD") == 0)
			phone_book.ft_add_new_contact();
		if (read_line.compare("SEARCH") == 0)
			phone_book.ft_search_for_contact();
		std::cout << "ʕ•́ᴥ•̀ʔっ\t";
		std::cin >> read_line;
	}
	return (0);
}