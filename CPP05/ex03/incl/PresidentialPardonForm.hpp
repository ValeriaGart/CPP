#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &to_copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(const PresidentialPardonForm &assign);

		void executeByForm(Bureaucrat const& bur) const;

	private:
		PresidentialPardonForm(void);
};

#endif