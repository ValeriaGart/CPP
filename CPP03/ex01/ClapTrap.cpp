#include "incl/ClapTrap.hpp"

ClapTrap::ClapTrap( std::string new_name ) : _name(new_name), _attack_damage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_energy_p = 10;
	this->_hit_p = 10;
	return ; 
}

ClapTrap::ClapTrap( ClapTrap const & to_copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = to_copy;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & to_assign) {
	std::cout << "ClapTrap copy operator called" << std::endl;
	if (this != &to_assign)
	{
		this->_name = to_assign._name;
		this->_hit_p = to_assign._hit_p;
		this->_energy_p = to_assign._energy_p;
		this->_attack_damage = to_assign._attack_damage;
	}
	return *this;
}

void 		ClapTrap::attack(const std::string& target) {
	if (this->_hit_p && this->_energy_p) {
		std::cout	<< "-1 Energy point\n"
					<< "ClapTrap " << this->_name << " attacks "
					<< target << ", causing " << this->_attack_damage
					<< " points of damage!" << std::endl;
		this->_energy_p--;
	} else {
		std::cout	<<  "ClapTrap " << this->_name << " unable to attack:-(" << std::flush;
		if (!this->_hit_p)
			std::cout << " No hit points left!" << std::endl;
		else
			std::cout << " No energy points left!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount < 0)
		amount = 0;
	if (amount > this->_hit_p)
		amount = _hit_p;
	this->_hit_p -= amount;
	if (this->_hit_p == 0) {
		std::cout	<< "ClapTrap " << this->_name << " has lost "
					<< amount << " hit points." << std::endl;
	}
	std::cout	<< "ClapTrap " << this->_name << " has "
				<< this->_hit_p << " hit points left!" << std::endl;
}

void 		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_p) {
		this->_energy_p--;
		this->_hit_p += amount;
		std::cout	<< "-1 Energy point\n"
					<< "ClapTrap " << this->_name << " gots "
					<< amount << " hit points repaired ^^" << std::endl;
	} else {
		std::cout	<< "ClapTrap " << this->_name << "unable to repair hit points. No Energy points left" << std::endl;
	}
}

int			ClapTrap::ft_get_attack_damage( void ) {
	return (this->_attack_damage);
}