#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & to_copy) {
	*this = to_copy;
	return ;
}

PmergeMe::~PmergeMe( void ) {
	return ;
}

PmergeMe &	PmergeMe::operator=(PmergeMe const & to_assign) {
	(void)to_assign;
	return *this;
}

void	PmergeMe::_fill_list(  ) {
	std::stringstream str(this->_before);
	std::string word;

	while (str >> word) {
		try {
			double d = std::stod(word);
			if (d >= 2147483648)
				throw std::invalid_argument("Out of range");
			this->_list.push_back((int)d);
		} catch (std::invalid_argument & e) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
	return ;
}

void	PmergeMe::_fill_deque(  ) {
	std::stringstream str(this->_before);
	std::string word;

	while (str >> word) {
		try {
			double d = std::stod(word);
			if (d >= 2147483648)
				throw std::invalid_argument("Out of range");
			this->_deque.push_back((int)d);
		} catch (std::invalid_argument & e) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
	return ;
}

PmergeMe::PmergeMe( int amount, char const *content[] ) {

	this->_before = "";

	for (int i = 1; i < amount; i++)
	{
		this->_before += content[i];
		if (i < amount - 1)
			this->_before += " ";
	}

	_fill_list();
	_fill_deque();
	this->_list = _list_sort( this->_list );
	_deque_sort();

    std::list<int>::iterator i = this->_list.begin()	;
	while (i != this->_list.end()) {
        std::cout << *i;
        if (++i != this->_list.end())
            std::cout << " ";
    }
    std::cout << std::endl;
	return ;
}

std::list<std::pair<int, int>>	PmergeMe::_list_pairing( std::list<int> to_sort ) {
	std::list<std::pair<int, int>> pairs;
	std::list<std::pair<int, int>> ret;
	auto i = to_sort.begin();
	int one, two;

	while (i != to_sort.end()) {
		one = *i;
		++i;
		if (i != to_sort.end())
			two = *i;
		else
			two = -42;
		pairs.emplace_back(std::min(one, two), std::max(one, two));
		if (i != to_sort.end())
			++i;
	}

	auto i2 = pairs.begin();
	while (i2 != pairs.end()) {
		if (i2->second != -42)
			ret.emplace_back(*i2);
		std::cout << i2->first << " " << i2->second << std::endl;
		++i2;
	}

    return (ret);
}

std::list<int>	PmergeMe::_list_sort( std::list<int>& to_sort ) {
	std::list<std::pair<int, int>> pairs;
	std::list<int> min, max;
	std::list<int> ret;

	for(auto itt = to_sort.begin(); itt != to_sort.end(); itt++)
        std::cout << *itt << std::endl;
	if (to_sort.size() == 0) {
        std::cerr << "Usage: " << "./PmergeMe" << " [positive nums]" << std::endl;
        exit(1) ;
    }
    if (to_sort.size() <= 1)
	    return (to_sort);

    pairs = _list_pairing( to_sort );

    auto i = pairs.begin();
	for (; i != pairs.end() ; ++i) {
		if (i->first != -42)
			min.push_back(i->first);
		if (i->second != -42) {
			max.push_back(i->second);
		}
	}
	std::cout << "min" << std::endl;
	std::list<int> sorted_mins = _list_sort(min);
	std::cout << "max" << std::endl;
	std::list<int> sorted_maxs = _list_sort(max);

	ret.splice(ret.end(), sorted_mins);
	ret.splice(ret.end(), sorted_maxs);

	return (ret);
}

void	PmergeMe::_deque_sort( void ) {
	if (this->_deque.size() == 0) {
		std::cerr << "Usage: " << "./PmergeMe" << " [positive nums]" << std::endl;
		exit(1) ;
	}
	if (this->_deque.size() == 1)
		return ;
	return ;
}