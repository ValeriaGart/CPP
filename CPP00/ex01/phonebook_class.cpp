#include "./incl/phonebook_class.hpp"

PhoneBook::PhoneBook() {
	this->_num_of_contacts = -1;
	this->_index = -1;
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void	PhoneBook::ft_instructions(void) {
	std::cout << std::endl << "_____Instructions to this phonebook_____" << std::endl;
	std::cout << "\ntype in :\n1) ADD\t\t to add new contact" << std::endl;
	std::cout << "2) SEARCH\t to search for a contact" << std::endl;
	std::cout << "3) EXIT\t\t to exit the program" << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "\n*Keep on mind that this phonebook can oly store 8 contacts max\n" << std::endl;
}

void	PhoneBook::ft_add_new_contact(void) {
	if (this->_index  == 7)
		this->_index = -1;
	if (this->_num_of_contacts < 7)
		this->_num_of_contacts++;
	this->_index++;
	std::cin.ignore();
	this->_contacts[this->_index].ft_new_contact(this->_num_of_contacts);
}

int	PhoneBook::_ft_get_index(void)
{
	int	index = -1, correct = 0;

	if (this->_num_of_contacts > -1) {
		while (!correct) {
			std::cout << "\nWhat index would you like to check? ^^" << std::endl << "> ";
			std::cin >> index;
			if (std::cin.eof()) return -1;
			if (std::cin.good() && (index >= 0 && index <= this->_num_of_contacts)) {
				correct++;
				std::cout << "Here you goooo..." << std::endl;
			}
			else {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    	        std::cout << "\n✘✘✘ Hah.. Index seems to be invalid ✘✘✘\n✘✘✘  Let's do it right this time!   ✘✘✘" << std::endl;
			}
		}
	}
	else
		std::cout << "\nNo contacts saved yet ಥ_ಥ" << std::endl;
	return (index);
}

void	PhoneBook::ft_search_for_contact(void) {
	int	index = -1, i = -1;

	std::cout << "\n_____Here is the list of your contacts_____" << std::endl;
	std::cout << "\n   index  |first name|last  name| nickname " << std::endl;
	while (++i < 8)
	{
		if (i <= this->_num_of_contacts)
			this->_contacts[i].ft_show_contact();
		else
			std::cout << "----------|----------|----------|----------" << std::endl;
	}
	index = this->_ft_get_index();
	if (index >= 0)
		this->_contacts[index].ft_found_contact();
}