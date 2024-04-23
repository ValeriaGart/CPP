#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form{
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