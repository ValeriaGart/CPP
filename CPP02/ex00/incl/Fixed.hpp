#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string.h>

class	Fixed {

	public:
		Fixed( void );
		Fixed(const Fixed& to_copy);
		~Fixed( void );
		Fixed& operator=(const Fixed& to_assign);

		int			getRawBits( void ) const;
		void 		setRawBits( int const raw );

	private:
		int					_fixed_point;
		static const int	_fractional = 8;
};

#endif