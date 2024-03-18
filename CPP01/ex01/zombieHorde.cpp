#include "incl/Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {
	
	int	i = 0;

	Zombie *new_zomb = new Zombie[N];

	while (i < N) {
		new_zomb[i].add_name(name);
		i++;
	}
	return new_zomb;
}