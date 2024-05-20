#include "incl/ScavTrap.hpp"

int	main( void ) {
	ClapTrap	one("Julia");
	ScavTrap	two("Ann");

	one.attack("Ann");
	two.takeDamage(one.ft_get_attack_damage());
	ScavTrap	three("Amanda");
	three.attack("Julia");
	one.takeDamage(three.ft_get_attack_damage());
	one.attack("Amanda");
	two.guardGate();
	one.beRepaired(8);
	std::cout	<< ".\n.\n.\n. . . Game over . . . \n\n" << std::endl;
	return (0);
}