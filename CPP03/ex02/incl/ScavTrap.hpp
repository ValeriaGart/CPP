#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	public:
		ScavTrap( std::string new_name  );
		ScavTrap(ScavTrap const & to_copy);
		~ScavTrap( void );

		ScavTrap &	operator=(ScavTrap const & to_assign);

		void guardGate();
		void attack(const std::string& target);
};

#endif