#include "incl/ScavTrap.hpp"

int	main( void ) {
	ClapTrap	one;
	ScavTrap	two("Ann");

	std::cout	<< "\n\nAnn and Julia can't decide on who gets what dress for upcomming event,"
				<< " because obviously they can't both wear the same duhh🙄"<< std::endl;
	std::cout	<< "Julia says that Ann's chosen dress wouldn't fit to her eyes colour" << std::endl;
	one.attack("Ann");
	two.takeDamage(0);
	std::cout	<< "\nSeems like Ann is another opinion -_-"
				<< " The dress's colour is very neutral so those are"
				<< " the accessories that play more important role." << std::endl;
	std::cout	<< " Ann suggests to stop such destructive discussion and create a couple outfit instead."
				<< " Julia seems to be excited by that idea!💞\n" << std::endl;
	ScavTrap	three("Amanda");
	std::cout	<< "\nOh no.. Julias former bestie appears on horison and tries to steal chosen "
				<< "outfits! Doesn't seem like the things were fine btw those two-_-" << std::endl;
	three.attack("Julia");
	one.takeDamage(8);
	std::cout	<< "Fortunately Julia has partly healed her trauma over the time"
				<< " and is not as affected by a coward move as she could be. But still.. Auch 😟"
				<< std::endl;
	std::cout	<< "Ann enters the game again and protects the counter while Julia pays for stuff fast." << std::endl;
	two.guardGate();
	one.beRepaired(8);
	std::cout	<< "\nAaaand here they are the winners of the day! GJ team!🥳" << std::endl;
	std::cout	<< ".\n.\n.\n☀️ ☀️ ☀️ Game over ☀️ ☀️ ☀️ \n\n" << std::endl;
	return (0);
}