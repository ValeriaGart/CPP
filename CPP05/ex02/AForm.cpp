#include "./incl/AForm.hpp"

AForm::~AForm( void ) {
	std::cout << "AForm destructor  called" << std::endl;
	return ;
}

AForm::AForm( std::string name, std::string target, int signGrade, int execGrade) : 
_signGrade(signGrade), _executeGrade(execGrade), _name(name), _target(target) {
	
	std::cout << "AForm constructor called" << std::endl;

	if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());

	else if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	
	this->_signed = false;
	return ;
}

AForm::AForm( void ) : _signed(0), _signGrade(1000), _executeGrade(1000){
	return ; 
}

AForm::AForm( AForm const & to_copy) : _name(to_copy.getName()), _signed(to_copy.getSigned()), _target(to_copy.getTarget()),
									_signGrade(to_copy.getSignGrade()), _executeGrade(to_copy.getExecuteGrade()) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & to_assign) {
	std::cout << "Equality operator for |" << this->getName() << "| is called" << std::endl;
	this->_signed = to_assign.getSigned();
	return *this;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		this->_signed = true;
		bureaucrat.signForm(this->getName(), this->_signed);
	}
	else {
		bureaucrat.signForm(this->getName(), this->_signed);
		throw (AForm::GradeTooLowException());
	}
}

const std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::getSigned(void) const {
	return (this->_signed);
}

int		AForm::getSignGrade(void) const {
	return (this->_signGrade);
}

const std::string		AForm::getTarget(void) const {
	return (this->_target);
}

int		AForm::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

void AForm::execute(Bureaucrat const& bur) const {
	 this->executeByForm(bur);
}

std::ostream&   operator<<( std::ostream& out, const AForm& form ) {
	out << form.getName() << " form:\nSigned:\t\t\t" << form.getSigned()
		<< "\nSign Grade:\t\t" << form.getSignGrade()
		<< "\nExecute Grade:\t\t" << form.getExecuteGrade() << std::endl;
	return out;
}
