#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
	unsigned int 	_size;
	T*				_arr;
public: 
	Array( void );
	Array(const unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index) const;
    unsigned int size() const;
} ;

template <typename T>
Array<T>::Array() {
    this->_size = 0;
    this->_arr = nullptr ;
}

template <typename T>
Array<T>::~Array() {
	if (this->_arr)
		delete []this->_arr;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_size = n;
	this->_arr = new T[_size]();
	if(!this->_arr)
	{
		this->_size = 0;
		std::cerr << "Allocation has failed. Array set to null, size is 0." << std::endl;
	}
}

template <typename T>
Array<T>::Array(const Array& to_copy) : _arr(new T[to_copy._size]()), _size(to_copy._size) {
		if (this->_arr) {
			for (unsigned int i = 0; i < this->_size; ++i) {
			    this->_arr[i] = to_copy._arr[i];
			}
		}
		return ;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& to_copy) {
	if (this != &to_copy) {
		delete[] this->_arr;
		this->_size = to_copy._size;
		this->_arr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; ++i) {
			this->_arr[i] = to_copy._arr[i];
		}
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int ind) const {
	if (ind >= this->_size || ind < 0) {
		throw std::out_of_range("Wrong index:-(");
	}
	return this->_arr[ind];
}

#endif