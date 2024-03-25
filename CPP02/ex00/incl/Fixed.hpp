#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class	Fixed {

	public:
		Fixed( void );
		Fixed(Fixed const & to_copy);
		~Fixed( void );

		Fixed &		operator=(Fixed const & to_assign);
		std::string	getRawBits( void );

	private:
};

// optional but cool
//std::ostream &	operator<<(std::ostream COUT, Canonical const & canonical);

#endif