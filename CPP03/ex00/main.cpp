#include "incl/ClapTrap.hpp"

int	main( void ) {
	ClapTrap	one("Greg");
	ClapTrap	two("Sophie");

	one.attack("Sophie");
	two.takeDamage(one.ft_get_attack_damage());
	two.beRepaired(5);
	two.attack("Greg");
	one.takeDamage(two.ft_get_attack_damage());
	two.attack("Sophie");
	two.takeDamage(one.ft_get_attack_damage());
	std::cout	<< ".\n.\n.\nGame over\n\n" << std::endl;
	return (0);
}