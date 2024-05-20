#include "incl/Data.hpp"

Data::Data() {
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data& to_copy) {
	std::cout << "Data copy constructor called" << std::endl;
	*this = to_copy;
}

Data& Data::operator=(const Data& to_assign) {
	std::cout << "Data copy assignment operator called" << std::endl;
	(void) to_assign;
	return (*this);
}

Data::~Data( void ) {
	std::cout << "Data destructor called" << std::endl;
}

std::string Data::ft_get_name() const {
    return (this->_name);
}