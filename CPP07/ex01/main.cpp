#include "incl/iter.hpp"


void ft_print_int(int &nums) {
    std::cout << nums << " ";
}

void ft_print_str(std::string &str) {
    std::cout << str << " ";
}

void reverse(std::string& str) {
	unsigned int n = str.length();
    for (unsigned int i = 0; i < n / 2; ++i) {
        std::swap(str[i], str[n - i - 1]);
    }
}

int	main() {
	int one_int[] = {100, 200, 300, 400, 500};
	std::string two_str[] = {"Hi", "rimDim", "lol", "Orange", "Sock"};	

	iter(one_int, 5, ft_print_int);
	iter(two_str, 5, ft_print_str);

	iter(one_int, 5, incr<int>);
	iter(two_str, 5, reverse);

	iter(one_int, 5, ft_print_int);
	iter(two_str, 5, ft_print_str);

	return (0);
}