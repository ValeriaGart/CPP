#ifndef PMERGEME_CLASS_H
# define PMERGEME_CLASS_H

#include <iostream>
#include <list>
#include <deque>
#include <chrono>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>


class	PmergeMe {

public:
	PmergeMe( int amount, char const *content[] );
	PmergeMe(PmergeMe const & to_copy);
	~PmergeMe( void );

	PmergeMe &	operator=(PmergeMe const & to_assign);

	void								printList_n_Deque();

	double								getListTime() const;
	double								getDequeTime() const;


	class PmergeMeError : public std::exception
        {
        private:
            std::string _msg;
        public:
            PmergeMeError(std::string msg) throw()
            {
                _msg = "Error has occurred... " + msg;
            }
            virtual const char* what() const throw()
            {
                return (_msg.c_str());
            }
            virtual ~PmergeMeError() throw() {}
    };

private:
	PmergeMe( void );

	void								_fill_list( void );
	void								_fill_deque( void );

	void								_list_sort( std::list<int>& to_sort );
	void								_deque_sort( std::deque<int>& to_sort );

	std::list<int>::iterator _gimme_next_list(std::list<int>::iterator it, int num);
	std::deque<int>::iterator _gimme_next_deque(std::deque<int>::iterator it, int num);

	std::list<std::list<int>>::iterator _gimme_next_list_of_list(std::list<std::list<int>>::iterator it, int num);
	std::deque<std::deque<int>>::iterator _gimme_next_deque_of_deque(std::deque<std::deque<int>>::iterator it, int num);

	void splitChunks(std::list<int>& to_sort, std::list<std::list<int> >& main, std::list<std::list<int> >& pend, int num);
	void splitChunks_deque(std::deque<int>& to_sort, std::deque<std::deque<int>>& main, std::deque<std::deque<int>>& pend, int num);

	long _jacobsthal_number(long num);

	std::list<int>				_list;
	std::list<std::list<int>>	_tmp;
	std::deque<std::deque<int>>	_tmp_deque;
	std::deque<int>				_deque;
	std::string					_original;
	int							_pair_lvl;
	double 						_time_elapsed_list;
	double 						_time_elapsed_deque;
};


#endif