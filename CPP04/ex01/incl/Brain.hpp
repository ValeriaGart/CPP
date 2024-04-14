#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain {
	public:
		Brain(Brain const & to_copy);
		Brain( void );
		~Brain( void );

		Brain &	operator=(Brain const & to_assign);
	private:
		std::string	ideas[100];
};

#endif