#ifndef CANONICAL_CLASS_H
# define CANONICAL_CLASS_H

#include <iostream>

class	Canonical {

	public:
		Canonical(Canonical const & to_copy);
		~Canonical( void );

		Canonical &	operator=(Canonical const & to_assign);

	private:
		Canonical( void );
};

// optional but cool
//std::ostream &	operator<<(std::ostream COUT, Canonical const & canonical);

#endif