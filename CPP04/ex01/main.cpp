#include "./incl/Dog.hpp"
#include "./incl/Cat.hpp"
#include "./incl/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* w = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	delete(meta), delete(j), delete(i);
	delete (w);

	std::cout << "\n\n-----------01_test-----------" << std::endl;
	const Animal* gang[10];

	for (size_t i = 0; i < 5; i += 1) {
		gang[i] = new Dog();
		gang[i]->makeSound();
		std::cout << std::endl;
	}

	for (size_t i = 5; i < 10; i += 1) {
		gang[i] = new Cat();
		gang[i]->makeSound();
		std::cout << std::endl;
	}

	for (size_t i = 0; i < 10; i += 1) {
		delete gang[i];
	}
	return 0;
}