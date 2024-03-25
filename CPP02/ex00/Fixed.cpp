#include "incl/Fixed.hpp"

Fixed::Fixed( void ) {
	return ; 
}

Fixed::Fixed( Fixed const & to_copy) {
	*this = to_copy;
}

Fixed::~Fixed( void ) {
	return ;
}

Fixed & Fixed::operator=(Fixed const & to_assign) {
	//copy all values

	return *this;
}

std::string	Fixed::getRawBits( void ) {

}