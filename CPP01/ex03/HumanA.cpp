#include "incl/HumanA.hpp"

void	HumanA::attack( void ) {
	if (this->_weapon.getType() == "") {
		std::cout << _name << " has no weapon to attack:-((" << std::endl;
		return ;
	}
	std::cout	<< this->_name << " attacks with their "
				<< this->_weapon.getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon& weeapon ) : _name(name), _weapon(weeapon) {
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}