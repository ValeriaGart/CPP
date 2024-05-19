#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

class	ScalarConverter {

	public:
		static void convert(const std::string &lit);

	private:
		ScalarConverter( void );
		ScalarConverter(ScalarConverter const & to_copy);
		ScalarConverter &	operator=(ScalarConverter const & to_assign);
		~ScalarConverter( void );
};

#endif