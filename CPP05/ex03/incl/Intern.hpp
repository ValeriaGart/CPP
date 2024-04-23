#ifndef  INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern( void );
		Intern(const Intern &to_copy);
		~Intern( void );

		Intern& operator=(const Intern &to_assign);

		Form *makeForm(std::string name, std::string target);	
};

#endif