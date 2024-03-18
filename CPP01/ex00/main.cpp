#include "incl/Zombie.hpp"

int main() {
	std::string	name;

	std::cout << "🧠 Name a zombie on the stack:\t";
	std::cin >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Zombie zombi1(name);

	std::cout << "🧠 Name a zombie on the heap:\t";
	std::cin >> name;

	Zombie *zombi2 = newZombie(name);

	zombi1.announce();

    zombi2->announce();
    delete zombi2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("Anna");
	return (0);
}