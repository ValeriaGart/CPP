#include "Canonical_class.hpp"

Canonical::Canonical( void ) {
	return ; 
}

Canonical::Canonical( Canonical const & to_copy) {
	*this = to_copy;
}

Canonical::~Canonical( void ) {
	return ;
}

Canonical & Canonical::operator=(Canonical const & to_assign) {
	//copy all values

	return *this;
}