#include "incl/ClapTrap.hpp"

int	main( void ) {
	ClapTrap	one("Greg");
	ClapTrap	two("Sophie");

	std::cout	<< "\n\nGreg and Sophie are having a verbal fight.."
				<< " Greg shoots with the words like bullets!"<< std::endl;
	one.attack("Sophie");
	two.takeDamage(7);
	std::cout	<< "Then at some point she reflects on her feelings "
				<< "and realises that Greg's accusations have no ground." << std::endl;
	two.beRepaired(5);
	std::cout	<< "She cowardly reminds him of some mistakes of his "
				<< "that happend in the past." << std::endl;
	two.attack("Greg");
	one.takeDamage(10);
	std::cout	<< "And Greg is defeated💪\n Is the taste of viktory sweet, Sophie?"
				<< "\nDoesn't seem like that.. Very fast she realises there are no winners in this game."
				<< std::endl;
	two.attack("Sophie");
	two.takeDamage(20);
	std::cout	<< ".\n.\n.\nGame over\n\n" << std::endl;
	return (0);
}