#include "BitcoinExchange.hpp"
//don't push input file

int main(int ac, char**av) {

	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}

	try {

		BitcoinExchange to_output(av[1]);

		to_output.outputValues();

	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return (0);
}