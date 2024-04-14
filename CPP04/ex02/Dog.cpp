#include "incl/Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& n) {
        std::cout << "Memory Allocation has failed : " << n.what() << std::endl;
    }
	return ; 
}

Dog::Dog(Dog const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

Dog::~Dog( void ) {
	if (this->_brain)
		delete  this->_brain;
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

Dog		& Dog::operator=(Dog const & to_assign) {
	std::cout << this->type << " equality operator is called" << std::endl;
	if (this != &to_assign) {
		if (this->_brain)
			delete this->_brain;
		this->type = to_assign.getType();
		try {
    		this->_brain = new Brain(*to_assign._brain);
    	}
    	catch (const std::bad_alloc& n) {
    		std::cout << "Memory Allocation has failed : " << n.what() << std::endl;
    	}
	}
	return *this;
}

std::string	Dog::getType() const {
	return (this->type);
}

void	Dog::makeSound( void ) const {
	std::cout << this->type << " says woof!" << std::endl;
}