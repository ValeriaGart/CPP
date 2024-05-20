#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

class	Serializer {

	private:
		Serializer( void );
		Serializer(Serializer const & to_copy);
		Serializer &	operator=(Serializer const & to_assign);
		~Serializer( void );
};

#endif