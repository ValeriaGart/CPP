#include "./incl/Form.hpp"

Form::~Form( void ) {
	std::cout << "Form destructor for |" << this->getName() << "| called" << std::endl;
	return ;
}

Form::Form( std::string name, int signGrade, int execGrade) : 
_signGrade(signGrade), _executeGrade(execGrade), _name(name) {
	
	std::cout << "Form constructor for |" << this->getName() << "| called" << std::endl;

	this->_signed = false;

	if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
	else if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	return ;
}

Form::Form( void ) : _signed(0), _signGrade(1000), _executeGrade(1000){
	return ; 
}

Form::Form( Form const & to_copy) : _name(to_copy.getName()), _signed(to_copy.getSigned()),
									_signGrade(to_copy.getSignGrade()), _executeGrade(to_copy.getExecuteGrade()) {
	std::cout << "Form copy constructor for |" << this->getName() << "| called" << std::endl;
	if (_signGrade > 150 || _executeGrade > 150)
		throw (Form::GradeTooLowException());
	else if (_signGrade < 1 || _executeGrade < 1)
		throw (Form::GradeTooHighException());
	*this = to_copy;
}

Form & Form::operator=(Form const & to_assign) {
	std::cout << "Equality operator for |" << this->getName() << "| is called" << std::endl;
	if (this != &to_assign)
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

int		Form::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

std::ostream&   operator<<( std::ostream& out, const Form& form ) {
	out << form.getName() << " form:\nSigned:\t\t" << form.getSigned()
		<< "\nSign Grade:\t\t" << form.getSignGrade()
		<< "\nExecute Grade:\t\t" << form.getExecuteGrade() << std::endl;
	return out;
}