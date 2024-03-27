#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {

	public:
		Fixed( void );
		Fixed(const int num);
        Fixed(const float num);
		Fixed(const Fixed& to_copy);
		~Fixed( void );

		Fixed& operator=(const Fixed& to_assign);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat(void)   const;
		int			toInt(void)     const;

		bool operator>(const Fixed& another) const;
		bool operator<(const Fixed& another) const;
		bool operator>=(const Fixed& another) const;
		bool operator<=(const Fixed& another) const;
		bool operator==(const Fixed& another) const;
		bool operator!=(const Fixed& another) const;

		Fixed operator+(const Fixed& another) const;
		Fixed operator-(const Fixed& another) const;
		Fixed operator*(const Fixed& another) const;
		Fixed operator/(const Fixed& another) const;

		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator++();
		Fixed operator--();

		static Fixed& 			min(Fixed& one, Fixed& two);
		static const Fixed& 	min(const Fixed& one, const Fixed& two);
		static Fixed& 			max(Fixed& one, Fixed& two);
		static const Fixed& 	max(const Fixed& one, const Fixed& two);

	private:
		int					_fixed_point;
		static const int	_fractional = 8;
};

std::ostream&   operator<<(std::ostream &out, Fixed const &to_print);

#endif