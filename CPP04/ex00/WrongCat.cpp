#include "incl/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	return ; 
}

WrongCat::WrongCat(WrongCat const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

WrongCat::~WrongCat( void ) {
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

WrongCat		& WrongCat::operator=(WrongCat const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign)
		this->type = to_assign.getType();
	return *this;
}

std::string	WrongCat::getType() const {
	return (this->type);
}

void	WrongCat::makeSound( void ) const {
	std::cout << this->type << " says meooooow ^^" << std::endl;
}