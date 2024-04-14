#include "incl/Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	return ; 
}

Cat::Cat(Cat const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

Cat::~Cat( void ) {
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

Cat		& Cat::operator=(Cat const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	Cat::getType() const {
	return (this->type);
}

void	Cat::makeSound( void ) const {
	std::cout << this->type << " says meooooow ^^" << std::endl;
}