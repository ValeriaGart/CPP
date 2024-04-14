#include "incl/Animal.hpp"

Animal::Animal( std::string str ) {
	this->type = str;
	std::cout << "Animal constructor is called" << std::endl;
}

Animal::Animal( void ) : type("Animal") {
	std::cout << "Default Animal constructor is called" << std::endl;
	return ; 
}

Animal::Animal( Animal const & to_copy) {
	std::cout << "Copy Animal constructor is called" << std::endl;
	*this = to_copy;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor is called" << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const & to_assign) {
	std::cout << "Animal equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	Animal::getType() const {
	return (this->type);
}
