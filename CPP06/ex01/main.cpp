#include "incl/Serializer.hpp"

int	main() {
	Data one;

	one.name = "Dave";

	uintptr_t two = Serializer::serialize(&one);
	Data *oneone = Serializer::deserialize(two);

	std::cout << &one << std::endl;
	std::cout << oneone << std::endl;
	if (&one == oneone)
		std::cout << "works" << std::endl;
	else
		std::cout << "fail" << std::endl;

	std::cout << one.name << std::endl;
	std::cout << oneone->name << std::endl;
	return (0);
}