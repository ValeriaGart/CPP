#include "incl/Replacer.hpp"

int main(int ac, char **av) {
	std::string	filename, s1, s2;

	if (ac != 4) {
		std::cout	<< "Wrong arguments! Enter 3 strings " 
					<< "where the first one is a filename-_-"
					<< std::endl;
		return (1);
	}

	Replacer	rep(av[1], av[2], av[3]);
	if (rep.replace() == false)
		return (1);
	return (0);
}