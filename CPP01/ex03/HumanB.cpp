#include "incl/HumanB.hpp"

void	HumanB::attack( void ) {
	if (this->_weapon == NULL) {
		std::cout << _name << " has no weapon to attack:-((" << std::endl;
		return ;
	}
	std::cout	<< this->_name << " attacks with their "
				<< this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

HumanB::HumanB( std::string name ) {
	this->_name = name;
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}