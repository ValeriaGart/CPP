#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {

	public:
		Dog(Dog const & to_copy);
		Dog( void );
		~Dog( void );

		Dog &			operator=(Dog const & to_assign);
		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif