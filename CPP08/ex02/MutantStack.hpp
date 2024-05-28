#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <list>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	
	MutantStack() { return; };
	~MutantStack() { return; };
	MutantStack(const MutantStack& to_copy) {
		*this = to_copy;
	}
	MutantStack& operator=(const MutantStack& to_copy) {
		std::stack<T, std::deque<T> >::operator=(to_copy);
		return (*this);
	}

	iterator begin() { return (this->c.begin()); };
	iterator end() { return (this->c.end()); };
} ;

#endif