#include "incl/Array.hpp"

int main() {
  unsigned int i;

  Array<int> one;
	std::cout << "Empty size: " << one.size() << std::endl;
	try {
		one[1] = 2;
	}
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
  }

  Array<int> two(2350);
	std::cout << "Int size: " << two.size() << std::endl;
	try {
        for (i = 0; i < 5; ++i)
    		  two[i] = i;
        for (i = 0; i < 5; ++i)
    		  std::cout << two[i] << " ";
        std::cout << std::endl;
	} 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Array<char> three(10);
    std::cout << "Char size: " << three.size() << std::endl;
    try {
        for (i = 0; i < 5; ++i)
    		two[i] = i + 97;
        for (i = 0; i < 5; ++i)
    		std::cout << two[i] << " ";
        std::cout << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
