#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "sp longest: " << sp.longestSpan() << std::endl;

	std::cout << "\n-- Copy constructor --" << std::endl;

	Span sp2(sp);
	std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;

	std::cout << "\n-- \"=\" operator --" << std::endl;

	Span sp3 = sp2;
	std::cout << "sp3 shortest: " << sp3.shortestSpan() << std::endl;
	std::cout << "sp3 longest: " << sp3.longestSpan() << "\n" << std::endl;

	std::vector<int> deq;
	for (int i = 0; i < 10001; ++i) {
		deq.push_back(rand());
	}

	try {
		Span x(10000);
		x.addMany(deq.begin(), deq.end());
		std::cout << "Shortest span: " << x.shortestSpan() << "\n";
		std::cout << "Longest span:  " << x.longestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		Span x(1);
		x.addNumber(1);
		std::cout << "Shortest span: " << x.shortestSpan() << "\n";
		std::cout << "Longest span:  " << x.longestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	return (0);
}