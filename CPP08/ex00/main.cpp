#include  "easyfind.hpp"

int main() {
	try {
		std::vector<int> vectorr = {1, 2, 3, 4, 5};
		std::vector<int>::iterator itVec = easyfind(vectorr, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;
	
		std::list<int> lisst = {11, 22, 33, 44, 55};
		std::list<int>::iterator itList = easyfind(lisst, 30);
		std::cout << "Found in list: " << *itList << std::endl;
		easyfind(vectorr, 100);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}