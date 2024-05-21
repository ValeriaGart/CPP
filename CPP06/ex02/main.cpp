#include "incl/A.hpp"
#include "incl/B.hpp"
#include "incl/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate( void ) {

    unsigned int random_num = std::rand() % 3;

    if (random_num == 0) {
		std::cout << "Random is A" << std::endl;
		return (new A());
	}
    if (random_num == 1) {
		std::cout << "Random is B" << std::endl;
		return (new B());
	}

	std::cout << "Random is C" << std::endl;
	return (new C());
}

void identify(Base* one) {

	if (dynamic_cast<A*>(one)) {
		std::cout << "casted pointer A" << std::endl;
	} else if (dynamic_cast<B*>(one)) {
			std::cout << "casted pointer B" << std::endl;
    } else if (dynamic_cast<C*>(one)) {
		std::cout << "casted pointer C" << std::endl;
	}
}

void identify(Base& one) {
	try {
		(void)dynamic_cast<A&>(one);
		std::cout << "casted ref A" << std::endl;
	} catch (std::exception &) { std::cout << "Bad ref cast C!" << std::endl; }
	try {
		(void)dynamic_cast<B&>(one);
		std::cout << "casted ref B" << std::endl;
	} catch (std::exception &) { std::cout << "Bad ref cast B!" << std::endl; }
	try {
		(void)dynamic_cast<C&>(one);
		std::cout << "casted ref C" << std::endl;
	} catch (std::exception &) { std::cout << "Bad ref cast C!" << std::endl; }
}

int main() {
	Base *one;

	std::srand(std::time(0));
	one = generate();
	if (one) {
		identify(one);
		identify(*one);
		delete one;
	} else {
		std::cout << "new failed" << std::endl;
		return (1);
	}

	return 0;
}