#include "Span.hpp"

Span::Span( void ) {return;}

Span::~Span( void ) {return;}

Span::Span( unsigned int N ): _n(N) {return;}

Span::Span(const Span& to_copy) {
	*this = to_copy;
}

Span& Span::operator=(const Span& to_copy) {
	if (this != &to_copy)
	{
		this->_n = to_copy._n;
		this->_vector = to_copy._vector;
	}
	return (*this);
}