#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &assign);

		void executeByForm(Bureaucrat const& bur) const;

	private:
		ShrubberyCreationForm(void);
};

#endif