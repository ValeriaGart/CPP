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

int	ft_print_av(int ac, char const *av[]) {
	int i = 1;
	for (; i < ac; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
	return ( i - 1 );
}

int main(int ac, char const *av[]) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " [positive nums]" << std::endl;
		return 1;
	}
	ft_inputcheck(ac, av);
	try {
		PmergeMe pm(ac, av);
		std::cout << "Before: ";
		int num = ft_print_av(ac, av);
		std::cout << "After: ";
		pm.printList_n_Deque();
		std::cout << "Time to process a range of " << num << " elements with std::list : " << pm.getListTime() << " us" << std::endl;
		std::cout << "Time to process a range of " << num << " elements with std::deque : " << pm.getDequeTime() << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}