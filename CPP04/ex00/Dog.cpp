#include "incl/Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	return ; 
}

Dog::Dog(Dog const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

Dog::~Dog( void ) {
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

Dog		& Dog::operator=(Dog const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	Dog::getType() const {
	return (this->type);
}

void	Dog::makeSound( void ) const {
	std::cout << this->type << " says woof!" << std::endl;
}