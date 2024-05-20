#include "incl/ScavTrap.hpp"
#include "incl/FragTrap.hpp"

int	main( void ) {

	ScavTrap one("Tony");
	ClapTrap two("Oh");
	FragTrap three("Heyo");

	three.highFivesGuys();
	one.attack("Heyo");
	three.takeDamage(one.ft_get_attack_damage());
	two.attack("Heyo");
	three.takeDamage(two.ft_get_attack_damage());
	three.highFivesGuys();
	one.attack("Heyo");
	three.takeDamage(one.ft_get_attack_damage());
	one.attack("Heyo");
	three.takeDamage(one.ft_get_attack_damage());
	one.attack("Heyo");
	three.takeDamage(one.ft_get_attack_damage());
	one.attack("Heyo");
	three.takeDamage(one.ft_get_attack_damage());
	three.highFivesGuys();
	return (0);
}