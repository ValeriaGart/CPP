#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal {

	public:
		WrongAnimal(WrongAnimal const & to_copy);
		WrongAnimal( std::string str );
		WrongAnimal( void );
		~WrongAnimal( void );

		WrongAnimal &	operator=(WrongAnimal const & to_assign);
		std::string		getType( void ) const;
		void	makeSound( void ) const;

	protected:
		std::string type;
};

#endif