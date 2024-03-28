#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <iostream>

class	ClapTrap {

	public:
		ClapTrap( std::string new_name );
		ClapTrap(ClapTrap const & to_copy);
		~ClapTrap( void );

		ClapTrap &	operator=(ClapTrap const & to_assign);

		void 		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int				_hit_p;
		int				_energy_p;
		int				_attack_damage;
};

#endif