#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
	int	i = 1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			if (i != 1)
				std::cout << " ";
			std::string arg = av[i];
        	for (char& c : arg)
            	c = std::toupper(c);
			std::cout << arg;
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}