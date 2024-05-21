#include "./incl/Form.hpp"

Form::~Form( void ) {
	std::cout << "Form destructor  called" << std::endl;
	return ;
}

Form::Form( std::string name, std::string target, int signGrade, int execGrade) : 
_signGrade(signGrade), _executeGrade(execGrade), _name(name), _target(target) {
	
	std::cout << "Form constructor called" << std::endl;

	if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());

	else if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	
	this->_signed = false;
	return ;
}

Form::Form( void ) : _signed(0), _signGrade(1000), _executeGrade(1000){
	return ; 
}

Form::Form( Form const & to_copy) : _name(to_copy.getName()), _signed(to_copy.getSigned()), _target(to_copy.getTarget()),
									_signGrade(to_copy.getSignGrade()), _executeGrade(to_copy.getExecuteGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(Form const & to_assign) {
	std::cout << "Equality operator for |" << this->getName() << "| is called" << std::endl;
	this->_signed = to_assign.getSigned();
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		this->_signed = true;
		bureaucrat.signForm(this->getName(), this->_signed);
	}
	else {
		bureaucrat.signForm(this->getName(), this->_signed);
		throw (Form::GradeTooLowException());
	}
}

const std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::getSigned(void) const {
	return (this->_signed);
}

int		Form::getSignGrade(void) const {
	return (this->_signGrade);
}

const std::string		Form::getTarget(void) const {
	return (this->_target);
}

int		Form::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

void Form::execute(Bureaucrat const& bur) const {
	 this->executeByForm(bur);
}

std::ostream&   operator<<( std::ostream& out, const Form& form ) {
	out << form.getName() << " form:\nSigned:\t\t\t" << form.getSigned()
		<< "\nSign Grade:\t\t" << form.getSignGrade()
		<< "\nExecute Grade:\t\t" << form.getExecuteGrade() << std::endl;
	return out;
}