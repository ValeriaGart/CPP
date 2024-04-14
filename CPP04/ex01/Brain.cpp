#include "./incl/Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Default Brain constructor is called" << std::endl;
	return ; 
}

Brain::Brain( Brain const & to_copy) {
	std::cout << "Copy Brain constructor is called" << std::endl;
	*this = to_copy;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor is called" << std::endl;
	return ;
}

Brain & Brain::operator=(Brain const & to_assign) {
	std::cout << "Brain equality operator is called" << std::endl;
    if ( this != &to_assign ) {
        for ( int i = 0; i < 100; i++ ) {
            this->ideas[i] = to_assign.ideas[i];
        }
    }
	return *this;
}