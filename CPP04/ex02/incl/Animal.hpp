#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	Animal {

	public:
		Animal(Animal const & to_copy);
		Animal( std::string str );
		Animal( void );
		virtual ~Animal( void );

		Animal &	operator=(Animal const & to_assign);
		std::string	getType( void ) const;
		virtual void	makeSound( void ) const = 0;

	protected:
		std::string type;
};

#endif