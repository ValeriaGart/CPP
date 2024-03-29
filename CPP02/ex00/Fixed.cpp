#include "./incl/Fixed.hpp"

Fixed::Fixed( void ) : _fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
	return ; 
}

Fixed::Fixed(const Fixed& to_copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed& to_assign) {
	//copy all values
	std::cout << "Copy operator called" << std::endl;
	if (this != &to_assign) {
		this->_fixed_point = to_assign.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits called" << std::endl;
	return (this->_fixed_point);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits called" << std::endl;
	this->_fixed_point = raw;
}
