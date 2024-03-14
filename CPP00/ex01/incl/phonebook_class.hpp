#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "contact_class.hpp"

class PhoneBook {

private:
	Contact _contacts[8];
	int		_num_of_contacts;

	int		_ft_get_index(void);

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	ft_instructions(void) ;
	void	ft_add_new_contact(void) ;
	void	ft_search_for_contact(void);
};

#endif