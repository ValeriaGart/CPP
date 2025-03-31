#include "Span.hpp"

Span::Span( void ) {return;}

Span::~Span( void ) {return;}

Span::Span( unsigned int N ): _n(N) {return;}

Span::Span(const Span& to_copy) {
	*this = to_copy;
}

unsigned int	Span::get_n( void ) const {
	return (this->_n);
}

std::deque<int>	Span::get_vector(void) const {
	return (this->_vector);
}

Span& Span::operator=(const Span& to_copy) {
	if (this != &to_copy)
	{
		this->_n = to_copy.get_n();
		this->_vector = to_copy.get_vector();
	}
	return (*this);
}

void Span::addNumber(int num) {
	if (this->_vector.size() + 1 > this->_n)
		throw std::out_of_range("Too many numbers");
	std::deque<int>::iterator it = std::upper_bound(this->_vector.begin(), this->_vector.end(), num);
	if (it != this->_vector.end())
		this->_vector.insert(it, num);
	else
		this->_vector.push_back(num);
}

long	Span::shortestSpan(void) {
	if (this->_vector.size() <= 1)
		throw std::out_of_range("Not enough elements for span");
		
	long span = std::numeric_limits<long>::max();
	long tmp;
	for (std::deque<int>::iterator it = this->_vector.begin() + 1; it != this->_vector.end(); ++it) {
		tmp = *it - *(it - 1);
		if (tmp < span)
			span = tmp;
	}
	return (span);
}
long	Span::longestSpan(void) const {
	if (this->_vector.size() <= 1)
		throw std::out_of_range("Not enough elements for span");
	return (*max_element(this->_vector.begin(), this->_vector.end()) - *min_element(this->_vector.begin(), this->_vector.end()));
}

void	Span::putDeq(void) {
	for (std::deque<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	Span::addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it < end; ++it)
		addNumber(*it);
}