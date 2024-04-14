#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	public:
		WrongCat(WrongCat const & to_copy);
		WrongCat( void );
		~WrongCat( void );

		WrongCat &		operator=(WrongCat const & to_assign);
		void	makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif