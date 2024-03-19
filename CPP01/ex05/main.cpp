#include "incl/Harl.hpp"

int main(int ac, char **av) {
	std::string	level = "";
	Harl		harl;

	while (level.compare("EXIT")) {
		std::cout << "★ Enter a level:\t";
		std::cin >> level;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		harl.complain(level);
	}
	return (0);
}