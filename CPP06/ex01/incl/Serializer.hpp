#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class	Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer( void );
		Serializer(Serializer const & to_copy);
		Serializer &	operator=(Serializer const & to_assign);
		~Serializer( void );
};

#endif