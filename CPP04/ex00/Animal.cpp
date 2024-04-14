#include "incl/Animal.hpp"

Animal::Animal( std::string str ) {
	this->type = str;
	std::cout << "Animal constructor is called" << std::endl;
}

Animal::Animal( void ) : type("Animal") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	return ; 
}

Animal::Animal( Animal const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

Animal::~Animal( void ) {
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound( void ) const {
	std::cout << this->type << " makes the animal sounds" << std::endl;
}