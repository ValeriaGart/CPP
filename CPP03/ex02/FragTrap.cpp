#include "incl/FragTrap.hpp"

FragTrap::FragTrap( std::string new_name ) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = new_name;
	this-> _attack_damage = 30;
	this->_energy_p = 100;
	this->_hit_p = 100;
	return ; 
}

FragTrap::FragTrap( FragTrap const & to_copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = to_copy;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & to_assign) {
	std::cout << "FragTrap copy operator called" << std::endl;
	if (this != &to_assign)
	{
		this->_name = to_assign._name;
		this->_hit_p = to_assign._hit_p;
		this->_energy_p = to_assign._energy_p;
		this->_attack_damage = to_assign._attack_damage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if ( !this->_energy_p || !this->_hit_p) {
		std::cout	<< "FragTrap " << this->_name << " can't give five:-(((";
		if (!this->_hit_p)
			std::cout << " No hit points left!" << std::endl;
		else
			std::cout << " No energy points left!" << std::endl;
	} else {
		std::cout	<< " FragTrap " << this->_name
					<< " gives high five 🤪" << std::endl;
		this->_energy_p--;
	}
}