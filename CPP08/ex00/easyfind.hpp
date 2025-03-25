#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#	include <iostream>
#	include <deque>
#	include <vector>
#	include <list>
#	include <iterator>
#	include <stdexcept>
#	include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int val) {
	typename T::iterator iter = std::find(cont.begin(), cont.end(), val);
	
	if (iter == cont.end())
		throw std::runtime_error("Element couldn't be found in the container");
	return (iter);
}

#endif