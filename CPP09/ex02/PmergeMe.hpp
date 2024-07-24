#ifndef PMERGEME_CLASS_H
# define PMERGEME_CLASS_H

#include <iostream>
#include <list>
#include <deque>
#include <chrono>
#include <stdexcept>
#include <cctype>
#include <sstream>

class	PmergeMe {

public:
	PmergeMe( int amount, char const *content[] );
	PmergeMe(PmergeMe const & to_copy);
	~PmergeMe( void );

	PmergeMe &	operator=(PmergeMe const & to_assign);

private:
	PmergeMe( void );

	void								_fill_list( void );
	void								_fill_deque( void );

	std::list<int>						_list_sort( std::list<int>& to_sort );
	void								_deque_sort( void );

	std::list<std::pair<int, int>>		_list_pairing( std::list<int> to_sort );

	std::list<int>		_list;
	std::deque<int>		_deque;
	std::string			_before;
};

#endif