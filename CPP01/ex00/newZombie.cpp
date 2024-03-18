#include "incl/Zombie.hpp"

Zombie* newZombie( std::string name ) {
	return (new Zombie( name ));
}
