#include "incl/ScalarConverter.hpp"

// c - char
// r - special float
// e - special double
// n - neither
char	ft_check_input(const std::string &lit) {
	if (lit.length() == 1 && std::isprint(lit[0]) && !std::isdigit(lit[0]))
		return ('c');
	if (lit == "+inff" || lit == "-inff" || lit == "nanf")
		return ('r');
	if (lit == "+inf" || lit == "-inf" || lit == "nan")
		return ('e');
	return ('n');
}

void	ft_try_convert(const std::string &lit) {
	errno = 0;
	long int_lit = std::strtol(lit.c_str(), NULL, 10);

	if (int_lit >= std::numeric_limits<char>::min() && int_lit <= std::numeric_limits<char>::max()) {
		char char_lit = static_cast<char>(int_lit);
		if (std::isprint(char_lit))
			std::cout << "char: '" << char_lit << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	if (errno == ERANGE || int_lit > std::numeric_limits<int>::max() || int_lit < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(int_lit) << std::endl;
	}

	float float_lit = std::strtof(lit.c_str(), NULL);
	if (errno == ERANGE) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "float: " << float_lit << "f" << std::endl;
	}	
	
	double double_lit = std::strtod(lit.c_str(), NULL);
	if (errno == ERANGE) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << double_lit << std::endl;
	}
}

void ScalarConverter::convert(const std::string &lit) {
	char	type;

	type = ft_check_input(lit);
	if (type == 'c') {
		std::cout << "char: '" << lit[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(lit[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(lit[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(lit[0]) << std::endl;
		return;
	}
	if (type == 'r') {
		float float_lit = std::strtof(lit.c_str(), NULL);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << float_lit << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(float_lit) << std::endl;
		return;
	}
	if (type == 'e') {
		double double_lit = std::strtod(lit.c_str(), NULL);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(double_lit) << "f" << std::endl;
		std::cout << "double: " << double_lit << std::endl;
		return;
	}	
	ft_try_convert(lit);
}


ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& to_copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& to_assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void) to_assign;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {
	std::cout << "Destructor called" << std::endl;
}