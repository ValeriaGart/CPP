#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << std::endl << "---Printing values---" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "---End of values---" << std::endl << std::endl;
	std::stack<int> s(mstack);

	std::cout << "--- List check ---" << std::endl;
	std::list<int> lst;
    lst.push_back(6);
    lst.push_back(17);
    std::cout << "back: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size: " << lst.size() << std::endl;
    lst.push_back(3);
    //lst.push_back(21474836499);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

	return (0);
}