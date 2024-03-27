#include "./incl/Fixed.hpp"

Fixed::Fixed( void ) : _fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
	return ; 
}

Fixed::Fixed(const Fixed& to_copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int num) : _fixed_point(num << this->_fractional) {
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fixed_point(roundf(num * (float)(1 << this->_fractional))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed& to_assign) {
	std::cout << "Copy operator called" << std::endl;
	if (this != &to_assign) {
		this->_fixed_point = to_assign.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& to_print) {
    out << to_print.toFloat();
    return out;
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixed_point) / (float)(1 << this->_fractional);
}

int	Fixed::toInt(void) const {
	return (roundf(this->toFloat()));
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits called" << std::endl;
	return (this->_fixed_point);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits called" << std::endl;
	this->_fixed_point = raw;
}
