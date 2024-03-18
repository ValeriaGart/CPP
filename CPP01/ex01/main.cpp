#include "incl/Zombie.hpp"

int main() {
	
	std::string name;
	int			i = 0;
	int			num_of_zombies = -1;

	std::cout << "Gimme the name: ";
	std::cin >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Gimme a num of zombies (0 - 100): ";
	while (num_of_zombies < 0 || num_of_zombies > 100)
	{
		std::cin >> num_of_zombies;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (num_of_zombies < 0 || num_of_zombies > 100)
			std::cout << "Heyoooo, gimme a num in range 0 - 100!-_- : ";
	}
	Zombie *new_horde = zombieHorde(num_of_zombies, name);	
	while (i < num_of_zombies) {
	    new_horde[i].announce();
		i++;
	}	
	delete [] new_horde;
	return (0);
}