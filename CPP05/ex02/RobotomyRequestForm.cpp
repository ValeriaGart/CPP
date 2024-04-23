#include "./incl/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout << "RobotomyRequestForm constructor called. Target:" << target << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getSignGrade(), to_copy.getExecuteGrade()) {
	std::cout << "RobotomyRequestForm copy constructor called. Target:" << this->getTarget() << std::endl;
	*this = to_copy;
}


RobotomyRequestForm::RobotomyRequestForm( void )
: AForm("RobotomyRequestForm", "target", 72, 45) {
	return ;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called. Target:" << this->getTarget() << std::endl;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &to_assign) {
	std::cout << "RobotomyRequestForm copy operator called. Target:" << this->getTarget() << std::endl;
	if (this == &to_assign)
		return *this;
	return *this;
}

void RobotomyRequestForm::executeByForm(Bureaucrat const& bur) const
{
	if (bur.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cerr	<< "RobotomyRequestForm couldn't be executed by "
					<< bur.getName() << " because it was not signed" << std::endl;
	else {
		std::cout << "Some drilling noises... " << std::endl;
		if (random() % 2 == 1)
			std::cout << "Target |" << this->getTarget() << "| is successfully robotomized :)" << std::endl;
		else
			std::cout << "Target |"<< this->getTarget() << "| failed to robotimize :(" << std::endl;
	}
}