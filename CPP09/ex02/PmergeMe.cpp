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

long PmergeMe::_jacobsthal_number(long num) { 
	long ret = round((pow(2, num + 1) + pow(-1, num)) / 3);

	return (ret);
}

double PmergeMe::getListTime() const {
	return this->_time_elapsed_list;
}

double PmergeMe::getDequeTime() const {
	return this->_time_elapsed_deque;
}

void	PmergeMe::_fill_deque(  ) {
	std::stringstream str(this->_original);
	std::string word;

	while (str >> word) {
		double d = std::stod(word);
		if (d >= 2147483648) {
			throw PmergeMeError("A number out of range."); }
		this->_deque.push_back((int)d);
	}
}

void	PmergeMe::_fill_list(  ) {
	std::stringstream str(this->_original);
	std::string word;

	while (str >> word) {
		double d = std::stod(word);
		if (d >= 2147483648) {
			throw PmergeMeError("A number out of range."); }
		this->_list.push_back((int)d);
	}
}

void PmergeMe::printList_n_Deque() {
	std::list<int>::const_iterator itl = this->_list.begin();
	std::deque<int>::const_iterator itd = this->_deque.begin();
	for (; itl != this->_list.end() && itd != this->_deque.end(); ++itl, ++itd) {
		if (*itl != *itd) {
			throw PmergeMeError("List and Deque are not sorted correctly.");
			return;
		}
		std::cout << *itl << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe( int amount, char const *content[] ) {

	this->_original = "";

	for (int i = 1; i < amount; i++)
	{
		this->_original += content[i];
		if (i < amount - 1)
			this->_original += " ";
	}

	_fill_list();
	_fill_deque();

	this->_pair_lvl = 1;
	clock_t start_list = clock();
	_list_sort( this->_list );
	clock_t end_list = clock();
	this->_time_elapsed_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC * 1000000;

	this->_pair_lvl = 1;
	clock_t start_deque = clock();
	_deque_sort( this->_deque );
	clock_t end_deque = clock();
	this->_time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;

	return ;
}

void PmergeMe::splitChunks_deque(std::deque<int>& to_sort, std::deque<std::deque<int>>& main, std::deque<std::deque<int>>& pend, int num) {
    std::deque<int>::iterator it = to_sort.begin();
    int chunkCount = 0;
    int i = 0;

    num /= 2;
    if (to_sort.size() == 3) {
        for (; i < 3; ++i, ++it) {
            std::deque<int> chunk;
            chunk.push_back(*it);
            if (i == 2) {
                pend.push_back(chunk);
            } else {
                main.push_back(chunk);
            }
        }
    }
    if (num == 0) {
        return;
    }

    while (it != to_sort.end()) {
        std::deque<int> chunk;
        i = 0;

        for (; i < num && it != to_sort.end(); ++i, ++it) {
            chunk.push_back(*it);
        }

        if (chunk.size() < num && chunk.size() != 0) {
            _tmp_deque.push_back(chunk);
        }
        if (chunk.size() < num) break;

        chunkCount++;

        if (chunkCount == 1 || chunkCount == 2 || chunkCount % 2 == 0) {
            main.push_back(chunk);
        } else {
            pend.push_back(chunk);
        }
    }

    if (main.size() > (pend.size() + 2)) {
        std::deque<int> last = main.back();
        main.pop_back();
        pend.push_back(last);
    }
	if (main.size() > 1){
		std::deque<int> last = main.back();
		main.pop_back();
		if (last.back() < main.back().back()) {
			pend.push_back(last); }
		else {
		main.push_back(last);}
	}
    /*if (num == 1) {
        std::deque<int> last = main.back();
        main.pop_back();
        std::deque<std::deque<int>>::iterator last_list_it = main.end();
        --last_list_it;
        if (last_list_it->back() > last.front()) {
            pend.push_back(last);
        } else {
            main.push_back(last);
        }
    }*/
}

/*void printChunks_deque(const std::deque<std::deque<int>>& chunks, const std::string& name) {
    std::cout << name << ":\n";
    for (std::deque<std::deque<int>>::const_iterator chunkIt = chunks.begin(); chunkIt != chunks.end(); ++chunkIt) {
        for (std::deque<int>::const_iterator numIt = chunkIt->begin(); numIt != chunkIt->end(); ++numIt) {
            std::cout << *numIt << " ";
        }
        std::cout << "\n";
    }
}*/


void PmergeMe::splitChunks(std::list<int>& to_sort, std::list<std::list<int> >& main, std::list<std::list<int> >& pend, int num) {
    std::list<int>::iterator it = to_sort.begin();
    int chunkCount = 0;
	int i = 0;

	num /= 2;
	if (to_sort.size() == 3) {
		for (; i < 3; ++i, ++it) {
			std::list<int> chunk;
			chunk.push_back(*it);
			if (i == 2) {
				pend.push_back(chunk);
			} else {
				main.push_back(chunk);
			}
		}
	}
	if (num == 0) {
		return;}
    while (it != to_sort.end()) {
        std::list<int> chunk;
		i = 0;

        for (; i < num && it != to_sort.end(); ++i, ++it) {
            chunk.push_back(*it);
        }

        if (chunk.size() < num && chunk.size() != 0) {
			_tmp.push_back(chunk);
		}
		if (chunk.size() < num) break;

        chunkCount++;

        if (chunkCount == 1 || chunkCount == 2 || chunkCount % 2 == 0) {
            main.push_back(chunk);
        } else {
            pend.push_back(chunk);
        }
    }

	if (main.size() > (pend.size() + 2)) {
		std::list<int> last = main.back();
		main.pop_back();
		pend.push_back(last);	
	}
	if (main.size() > 1){
		std::list<int> last = main.back();
		main.pop_back();
		if (last.back() < main.back().back()) {
			pend.push_back(last); }
		else {
		main.push_back(last);}
	}
	/*if(num == 1){
		std::list<int> last = main.back();
		main.pop_back();
		std::list<std::list<int> >::iterator last_list_it = main.end();
        --last_list_it;
		if (last_list_it->back() > last.front()) {
			pend.push_back(last); }
		else {
		main.push_back(last);}
	}*/
}

void printChunks(const std::list<std::list<int> >& chunks, const std::string& name) {
    std::cout << name << ":\n";
    for (std::list<std::list<int> >::const_iterator chunkIt = chunks.begin(); chunkIt != chunks.end(); ++chunkIt) {
        for (std::list<int>::const_iterator numIt = chunkIt->begin(); numIt != chunkIt->end(); ++numIt) {
            std::cout << *numIt << " ";
        }
        std::cout << "\n";
    }
}

std::deque<std::deque<int> >::iterator ft_get_insert_pos_deque( std::deque<std::deque<int> >& main, std::deque<std::deque<int> >::iterator pair, std::deque<std::deque<int> >::iterator pend)
{
    size_t len = 0;
    std::deque<std::deque<int> >::iterator high = main.begin();
    
    while (high != pair && high != main.end()) {
        ++high;
        ++len;
    }

    size_t lowIndex = 0;
    size_t highIndex = len;
    size_t midIndex;

    while (lowIndex < highIndex && len != 0) {
        midIndex = lowIndex + (highIndex - lowIndex) / 2;
        std::deque<std::deque<int> >::iterator low = main.begin() + lowIndex;
        std::deque<std::deque<int> >::iterator mid = main.begin() + midIndex;
        std::deque<std::deque<int> >::iterator highIt = main.begin() + highIndex;

        if (mid->back() == pend->back()) {
            return mid;
        } else if (mid->back() > pend->back()) {
            highIndex = midIndex;
        } else {
            lowIndex = midIndex + 1;
        }

        len = highIndex - lowIndex;
    }

    return main.begin() + lowIndex;
}

std::list<std::list<int> >::iterator ft_get_insert_pos(std::list<std::list<int> >& main, std::list<std::list<int> >::iterator pair, std::list<std::list<int> >::iterator pend) {
	size_t len = 0;
	std::list<std::list<int> >::iterator high = main.begin();
	while (len < main.size()) {
		if (high == pair) {
			break;
		}
		++high;
		++len;
	}
	std::list<std::list<int> >::iterator low;
	low = main.begin();
	std::list<std::list<int> >::iterator mid = main.begin();
	std::advance(mid, len / 2);
	while (low->back() <= high->back() && len != 0) {
		mid = low;
		std::advance(mid, len / 2);
		if (mid->back() == pend->back()) {
			return mid;
		} else if (mid->back() > pend->back()) {
			high = mid;
			std::advance(high, -1);
		} else {
			std::advance(low, (len / 2) + 1);
		}
		len /= 2;
	}

	return (low);
}

void	PmergeMe::_list_sort( std::list<int>& to_sort ) {

	int pair_units = to_sort.size() / this->_pair_lvl;
    if (pair_units < 2) {
        return;
	}

	int is_odd = 0; 
	if (pair_units % 2 == 1)
		is_odd = 1;
	std::list<int>::iterator start = to_sort.begin();
    std::list<int>::iterator last = this->_gimme_next_list(to_sort.begin(), (this->_pair_lvl * pair_units) - 1);
    std::list<int>::iterator end = this->_gimme_next_list(last, -(is_odd * this->_pair_lvl));

	int jump = 2 * this->_pair_lvl;

    for (std::list<int>::iterator it = start; it != end; std::advance(it, jump)) {
	    std::list<int>::iterator this_pair = this->_gimme_next_list(it, this->_pair_lvl - 1);
    	std::list<int>::iterator next_pair = this->_gimme_next_list(it, this->_pair_lvl * 2 - 1);
		if (*this_pair > *next_pair) {
    		std::list<int>::iterator s = this->_gimme_next_list(this_pair, -(this->_pair_lvl) + 1);
    		std::list<int>::iterator e = this->_gimme_next_list(s, this->_pair_lvl);
    		if (s != to_sort.end() && e != to_sort.end()) {
    			while (s != e)
    			{
    				std::list<int>::iterator next = this->_gimme_next_list(s, this->_pair_lvl);
    				if (next == to_sort.end()) break;
    				std::iter_swap(s, next);
    				++s;
    			}
    		}
    	}
    	if (next_pair == end) {
    		break; }
    }


	this->_pair_lvl *= 2;
	_list_sort( to_sort );
	this->_pair_lvl /= 2;

	std::list<std::list<int> > main;
    std::list<std::list<int> > pend;

	splitChunks(to_sort, main, pend, this->_pair_lvl);

	int prev = this->_jacobsthal_number(1);
	int inserted_num = 0;
	for (int iter = 2;; iter++) {
		int curr = this->_jacobsthal_number(iter);
		int diff = curr - prev;
		int offset = 0;
		if (diff > pend.size())
        	break;
		for (int i = 0; i < diff; i++) {
			std::list<std::list<int> >::iterator pend_it = this->_gimme_next_list_of_list(pend.begin(), diff - 1 - i);
			offset = 2 + diff + (inserted_num * 2);
			if (offset > main.size()) {
				break;
			}
			std::list<std::list<int> >::iterator pair = this->_gimme_next_list_of_list(main.begin(), (offset - 1));
			std::list<std::list<int> >::iterator insertPos = ft_get_insert_pos(main, pair, pend_it);
            std::list<std::list<int> >::iterator insert = main.insert(insertPos, *pend_it);
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
		}
		if (offset > main.size()) {
			break;
		}
		prev = curr;
    	inserted_num += diff;
	}
	
	for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        std::list<std::list<int> >::iterator curr_pend = this->_gimme_next_list_of_list(pend.begin(), i);
        std::list<std::list<int> >::iterator insertPos = ft_get_insert_pos(main, main.end(), curr_pend);
		if (insertPos == main.end()) {
			main.push_back(*curr_pend);
		} else {
        	main.insert(insertPos, *curr_pend);
		}
    }

	std::list<int> flatList;
    for (std::list<std::list<int> >::iterator outerIt = main.begin(); outerIt != main.end(); ++outerIt) {
        for (std::list<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt) {
            flatList.push_back(*innerIt);
        }
    }
	for (std::list<std::list<int> >::iterator outerIt = _tmp.begin(); outerIt != _tmp.end(); ++outerIt) {
        for (std::list<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt) {
            flatList.push_back(*innerIt);
        }
    }

	if (this->_pair_lvl != 1 || to_sort.size() == 3) {
    	to_sort = flatList;
	}
	_tmp.clear();
}

void	PmergeMe::_deque_sort( std::deque<int>& to_sort ) {
		int pair_units = to_sort.size() / this->_pair_lvl;
		if (pair_units < 2) {
			return;
		}
	
		int is_odd = 0;
		if (pair_units % 2 == 1)
			is_odd = 1;
		std::deque<int>::iterator start = to_sort.begin();
		std::deque<int>::iterator last = this->_gimme_next_deque(to_sort.begin(), (this->_pair_lvl * pair_units) - 1);
		std::deque<int>::iterator end = this->_gimme_next_deque(last, -(is_odd * this->_pair_lvl));
	
		int jump = 2 * this->_pair_lvl;
	
		for (std::deque<int>::iterator it = start; it != end; std::advance(it, jump)) {
			std::deque<int>::iterator this_pair = this->_gimme_next_deque(it, this->_pair_lvl - 1);
			std::deque<int>::iterator next_pair = this->_gimme_next_deque(it, this->_pair_lvl * 2 - 1);
			if (*this_pair > *next_pair) {
				std::deque<int>::iterator s = this->_gimme_next_deque(this_pair, -(this->_pair_lvl) + 1);
				std::deque<int>::iterator e = this->_gimme_next_deque(s, this->_pair_lvl);
				if (s != to_sort.end() && e != to_sort.end()) {
					while (s != e) {
						std::deque<int>::iterator next = this->_gimme_next_deque(s, this->_pair_lvl);
						if (next == to_sort.end()) break;
						std::iter_swap(s, next);
						++s;
					}
				}
			}
			if (next_pair == end) {
				break;
			}
		}
	
		this->_pair_lvl *= 2;
		_deque_sort(to_sort);
		this->_pair_lvl /= 2;
	
		std::deque<std::deque<int>> main;
		std::deque<std::deque<int>> pend;
	
		splitChunks_deque(to_sort, main, pend, this->_pair_lvl);
	
		int prev = this->_jacobsthal_number(1);
		int inserted_num = 0;
		for (int iter = 2;; iter++) {
			int curr = this->_jacobsthal_number(iter);
			int diff = curr - prev;
			int offset = 0;
			if (diff > pend.size())
				break;
			for (int i = 0; i < diff; i++) {
				std::deque<std::deque<int>>::iterator pend_it = this->_gimme_next_deque_of_deque(pend.begin(), diff - 1 - i);
				offset = 2 + diff + (inserted_num * 2);
				if (offset > main.size()) {
					break;
				}
				std::deque<std::deque<int>>::iterator pair = this->_gimme_next_deque_of_deque(main.begin(), (offset - 1));
				std::deque<std::deque<int>>::iterator insertPos = ft_get_insert_pos_deque(main, pair, pend_it);
				std::deque<std::deque<int>>::iterator insert = main.insert(insertPos, *pend_it);
				pend_it = pend.erase(pend_it);
				std::advance(pend_it, -1);
			}
			if (offset > main.size()) {
				break;
			}
			prev = curr;
			inserted_num += diff;
		}
	
		for (ssize_t i = pend.size() - 1; i >= 0; i--) {
			std::deque<std::deque<int>>::iterator curr_pend = this->_gimme_next_deque_of_deque(pend.begin(), i);

			std::deque<std::deque<int>>::iterator insertPos = ft_get_insert_pos_deque(main, main.end(), curr_pend);
			if (insertPos == main.end()) {
				main.push_back(*curr_pend);
			} else {
				main.insert(insertPos, *curr_pend);
			}
		}
	
		std::deque<int> flatList;
		for (std::deque<std::deque<int>>::iterator outerIt = main.begin(); outerIt != main.end(); ++outerIt) {
			for (std::deque<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt) {
				flatList.push_back(*innerIt);
			}
		}
		for (std::deque<std::deque<int>>::iterator outerIt = _tmp_deque.begin(); outerIt != _tmp_deque.end(); ++outerIt) {
			for (std::deque<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt) {
				flatList.push_back(*innerIt);
			}
		}
	
		if (this->_pair_lvl != 1 || to_sort.size() == 3) {
			to_sort = flatList;
		}
		_tmp_deque.clear();
	}
	

std::list<int>::iterator PmergeMe::_gimme_next_list(std::list<int>::iterator it, int num) {
	std::advance(it, num);
    return it;
}

std::list<std::list<int>>::iterator PmergeMe::_gimme_next_list_of_list(std::list<std::list<int>>::iterator it, int num) {
	std::advance(it, num);
    return it;
}

std::deque<std::deque<int>>::iterator PmergeMe::_gimme_next_deque_of_deque(std::deque<std::deque<int>>::iterator it, int num) {
	std::advance(it, num);
    return it;
}

std::deque<int>::iterator PmergeMe::_gimme_next_deque(std::deque<int>::iterator it, int num) {
	std::advance(it, num);
    return it;
}

