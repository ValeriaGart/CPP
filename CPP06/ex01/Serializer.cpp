#include "incl/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& to_copy) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = to_copy;
}

Serializer& Serializer::operator=(const Serializer& to_assign) {
	std::cout << "Serializer copy assignment operator called" << std::endl;
	(void) to_assign;
	return (*this);
}

Serializer::~Serializer( void ) {
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}