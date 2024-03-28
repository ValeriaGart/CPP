#include "incl/ScavTrap.hpp"

ScavTrap::ScavTrap( std::string new_name ) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = new_name;
	this-> _attack_damage = 20;
	this->_energy_p = 50;
	this->_hit_p = 100;
	return ; 
}

ScavTrap::ScavTrap( ScavTrap const & to_copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = to_copy;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & to_assign) {
	std::cout << "ScavTrap copy operator called" << std::endl;
	if (this != &to_assign)
	{
		this->_name = to_assign._name;
		this->_hit_p = to_assign._hit_p;
		this->_energy_p = to_assign._energy_p;
		this->_attack_damage = to_assign._attack_damage;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap " << this->_name
				<< " is now in the Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_p && this->_energy_p) {
		std::cout	<< "-1 Energy point\n"
					<< "ScavTrap " << this->_name << " attacks "
					<< target << ", causing " << this->_attack_damage
					<< " points of damage!" << std::endl;
		this->_energy_p--;
	} else {
		std::cout	<<  "ScavTrap " << this->_name << " unable to attack:-(" << std::flush;
		if (!this->_hit_p)
			std::cout << " No hit points left!" << std::endl;
		else
			std::cout << " No energy points left!" << std::endl;
	}
}
