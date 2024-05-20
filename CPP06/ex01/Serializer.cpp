#include "incl/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& to_copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Serializer& Serializer::operator=(const Serializer& to_assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void) to_assign;
	return (*this);
}

Serializer::~Serializer( void ) {
	std::cout << "Destructor called" << std::endl;
}