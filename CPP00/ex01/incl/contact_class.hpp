#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class Contact {

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_the_darkest_secret;
	int			_index;

	std::string	_ft_get_string(std::string str);
	void		_ft_put_cut_value(std::string str, std::string cut_str);
	int			_is_ascii(const std::string& s);

public:

	Contact(void);
	~Contact(void);

	void		ft_new_contact(int index);
	void		ft_show_contact(void);
	void		ft_found_contact(void);
};

#endif