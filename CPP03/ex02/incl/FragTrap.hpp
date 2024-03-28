#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	public:
		FragTrap( std::string new_name  );
		FragTrap(FragTrap const & to_copy);
		~FragTrap( void );

		FragTrap &	operator=(FragTrap const & to_assign);

		void guardGate();
		void attack(const std::string& target);
};

#endif