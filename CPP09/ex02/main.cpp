#include "PmergeMe.hpp"
#include <iostream>

void	ft_inputcheck(int ac, char const *av[]) {
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!std::isdigit(av[i][j]) && !std::isspace(av[i][j])) {
				if (av[i][j] == '+' && isdigit(av[i][j + 1]) && (j == 0 || isspace(av[i][j - 1])))
					continue ;
				std::cout << "Error: Invalid input" << std::endl;
				exit(1);
			}
		}
	}
}

int main(int ac, char const *av[]) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " [positive nums]" << std::endl;
		return 1;
	}
	ft_inputcheck(ac, av);
	PmergeMe pm(ac, av);
	return 0;
}