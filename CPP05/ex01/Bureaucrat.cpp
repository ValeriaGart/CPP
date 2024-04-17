#include "./incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade) {
	return ; 
}

Bureaucrat::Bureaucrat( void ) : _name(NULL), _grade(-1) {
	return ; 
}

Bureaucrat::Bureaucrat( Bureaucrat const & to_copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = to_copy;
}

Bureaucrat::~Bureaucrat( void ) {
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & to_assign) {
	std::cout << " Equality operator is called" << std::endl;
	if (this != &to_assign) {
		this->_grade = to_assign.getGrade();
    }
	return *this;
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int			Bureaucrat::getGrade() const {
	return (this->_grade);
}

void    Bureaucrat::incrementGrade() {
    if ( this->_grade <= 0 )
        throw Bureaucrat::GradeTooHighException();
	else {
		(this->_grade)--;
	    if ( this->_grade <= 0 )
	        throw Bureaucrat::GradeTooHighException();
	}
}

void    Bureaucrat::decrementGrade() {
    if ( this->_grade > 149 )
        throw Bureaucrat::GradeTooLowException();
	else {
		(this->_grade)++;
		if ( this->_grade > 150 )
        	throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream&   operator<<( std::ostream& out, const Bureaucrat& bur ) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}