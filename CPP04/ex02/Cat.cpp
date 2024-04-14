#include "incl/Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Default " << this->type << " constructor is called" << std::endl;
	try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& n) {
        std::cout << "Memory Allocation has failed : " << n.what() << std::endl;
    }
	return ; 
}

Cat::Cat(Cat const & to_copy) {
	std::cout << "Copy " << this->type << " constructor is called" << std::endl;
	*this = to_copy;
}

Cat::~Cat( void ) {
	if (this->_brain)
		delete  this->_brain;
	std::cout << this->type << " destructor is called" << std::endl;
	return ;
}

Cat		& Cat::operator=(Cat const & to_assign) {
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

std::string	Cat::getType() const {
	return (this->type);
}

void	Cat::makeSound( void ) const {
	std::cout << this->type << " says meooooow ^^" << std::endl;
}