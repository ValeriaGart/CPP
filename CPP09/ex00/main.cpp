#include "BitcoinExchange.hpp"
//don't push input file

int main(int ac, char**av) {

	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}

	BitcoinExchange to_output(av[1]);

	to_output.outputValues();

	return (0);
}