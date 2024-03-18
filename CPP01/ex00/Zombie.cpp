#include "incl/Zombie.hpp"

Zombie::Zombie( std::string new_name ) {
	this->_name = new_name;
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
