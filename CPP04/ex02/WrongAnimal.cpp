#include "incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( std::string str ) {
	std::cout << "WrongAnimal constructor is called" << std::endl;
	this->type = str;
}

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	return ; 
}

WrongAnimal::WrongAnimal( WrongAnimal const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << this->type << " makes the wrong animal sounds" << std::endl;
}