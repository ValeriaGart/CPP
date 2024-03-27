#include "./incl/Fixed.hpp"

Fixed::Fixed( void ) : _fixed_point(0) {
	return ; 
}

Fixed::Fixed(const Fixed& to_copy) {
	*this = to_copy;
}

Fixed::Fixed(const int num) : _fixed_point(num << this->_fractional) {
}

Fixed::Fixed(const float num) : _fixed_point(roundf(num * (float)(1 << this->_fractional))) {
}

Fixed::~Fixed( void ) {
	return ;
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixed_point) / (float)(1 << this->_fractional);
}

int	Fixed::toInt(void) const {
	return (roundf(this->toFloat()));
}

int	Fixed::getRawBits( void ) const {
	return (this->_fixed_point);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed& to_assign) {
	if (this != &to_assign) {
		this->_fixed_point = to_assign.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& to_print) {
    out << to_print.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& another) const {
    return (_fixed_point > another._fixed_point);
}

bool Fixed::operator<(const Fixed& another) const {
    return (_fixed_point < another._fixed_point);
}

bool Fixed::operator>=(const Fixed& another) const {
    return (_fixed_point >= another._fixed_point);
}

bool Fixed::operator<=(const Fixed& another) const {
    return (_fixed_point <= another._fixed_point);
}

bool Fixed::operator==(const Fixed& another) const {
    return (_fixed_point == another._fixed_point);
}

bool Fixed::operator!=(const Fixed& another) const {
    return (_fixed_point != another._fixed_point);
}

Fixed Fixed::operator+(const Fixed& another) const
{
    Fixed ret(this->toFloat() + another.toFloat());
    return (ret);
}

Fixed Fixed::operator-(const Fixed& another) const
{
    Fixed ret(this->toFloat() - another.toFloat());
    return (ret);
}

Fixed Fixed::operator*(const Fixed& another) const
{
    Fixed ret(this->toFloat() * another.toFloat());
    return (ret);
}

Fixed Fixed::operator/(const Fixed& another) const
{
    Fixed ret(this->toFloat() / another.toFloat());
    return (ret);
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    this->setRawBits((this->getRawBits()) + 1);
    return (ret);
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    this->setRawBits((this->getRawBits()) - 1);
    return (ret);
}

Fixed Fixed::operator++()
{
    this->setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator--()
{
    this->setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
    return (one < two ? one : two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{    
    return (one < two ? one : two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    return (one > two ? one : two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
    return (one > two ? one : two);
}