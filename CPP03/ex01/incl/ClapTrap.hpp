#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <iostream>

class	ClapTrap {

	public:
		ClapTrap( std::string new_name = "Julia" );
		ClapTrap(ClapTrap const & to_copy);
		~ClapTrap( void );

		ClapTrap &	operator=(ClapTrap const & to_assign);

		void 		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		int			ft_get_attack_damage( void );

	protected:
		std::string		_name;
		int				_hit_p;
		int				_energy_p;
		int				_attack_damage;
};

#endif