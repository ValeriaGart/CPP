#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {

	public:
		Cat(Cat const & to_copy);
		Cat( void );
		~Cat( void );

		Cat &			operator=(Cat const & to_assign);
		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
	private:
		Brain	*_brain;
};

#endif