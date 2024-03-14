#include "./incl/contact_class.hpp"

Contact::Contact()
{
    return ;
}

Contact::~Contact()
{
    return ;
}

std::string	Contact::_ft_get_string(std::string str)
{
    std::string input = "";
    int correct = 0;

    while (!correct)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            correct++;
        else 
        {
            std::cin.clear();
            std::cout << "Incorrect input:-(" << std::endl;
        }
    }
    return (input);
}

void	Contact::ft_new_contact(int index) {
    this->_index = index;
    this->_first_name = this->_ft_get_string("Enter the first name: ");
    this->_last_name = this->_ft_get_string("Enter the last name: ");
    this->_nickname = this->_ft_get_string("Enter the nickname: ");
    this->_phone_number = this->_ft_get_string("Enter the phone number: ");
    this->_the_darkest_secret = this->_ft_get_string("Enter the darkest secret: ");
}

void	Contact::_ft_put_cut_value(std::string str, std::string cut_str)
{
    int spaces;

    if (str.length() > 10)
        cut_str[9] = '.';
    spaces = 10 - cut_str.length();
    std::cout << cut_str << std::flush;
    ++spaces;
    while (--spaces)
        std::cout << " " << std::flush;
}

void		Contact::ft_show_contact(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;

    first_name = this->_first_name.substr(0, 10);
    last_name = this->_last_name.substr(0, 10);
    nickname = this->_nickname.substr(0, 10);
    std::cout << this->_index << "         " << "|" << std::flush;
    this->_ft_put_cut_value(this->_first_name, first_name);
    std::cout << "|" << std::flush;
    this->_ft_put_cut_value(this->_last_name, last_name);
    std::cout << "|" << std::flush;
    this->_ft_put_cut_value(this->_nickname, nickname);
    std::cout << std::endl;
}

void		Contact::ft_found_contact(void)
{
    std::cout << "first name:\t" << this->_first_name << std::endl;
    std::cout << "last name:\t" << this->_last_name << std::endl;
    std::cout << "nickname:\t" << this->_nickname << std::endl;
    std::cout << "phone number:\t" << this->_phone_number << std::endl;
    std::cout << "the darkest secret:\t" << this->_the_darkest_secret << std::endl;
}