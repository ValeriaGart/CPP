#include "incl/Zombie.hpp"

Zombie::Zombie( void ) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout	<< "Destructor is called..Zombie " << this->_name
				<< " says goodbye (っ◔◡◔)っ ❤" << std::endl;
	return ;
}

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::add_name( std::string name ) {
	this->_name = name;
}