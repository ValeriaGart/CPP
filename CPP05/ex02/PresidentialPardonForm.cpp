#include "./incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout << "PresidentialPardonForm constructor called. Target:" << target << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getSignGrade(), to_copy.getExecuteGrade()) {
	std::cout << "PresidentialPardonForm copy constructor called. Target:" << this->getTarget() << std::endl;
	*this = to_copy;
}


PresidentialPardonForm::PresidentialPardonForm( void )
: AForm("PresidentialPardonForm", "target", 25, 5) {
	return ;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called. Target:" << this->getTarget() << std::endl;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &to_assign) {
	std::cout << "PresidentialPardonForm copy operator called. Target:" << this->getTarget() << std::endl;
	if (this == &to_assign)
		return *this;
	return *this;
}

void PresidentialPardonForm::executeByForm(Bureaucrat const& bur) const
{
	if (bur.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cerr	<< "PresidentialPardonForm couldn't be executed by "
					<< bur.getName() << " because it was not signed" << std::endl;
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}