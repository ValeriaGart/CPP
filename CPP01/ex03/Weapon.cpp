#include "incl/Weapon.hpp"

Weapon::Weapon( std::string type ) {
	this->setType(type);
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

void	Weapon::setType( std::string to_set_type )	{
	this->type = to_set_type;
}

const std::string&	Weapon::getType( void )	{
	return (this->type);
}