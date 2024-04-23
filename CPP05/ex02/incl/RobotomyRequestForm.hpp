#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(const RobotomyRequestForm &assign);

		void executeByForm(Bureaucrat const& bur) const;

	private:
		RobotomyRequestForm(void);
};

#endif