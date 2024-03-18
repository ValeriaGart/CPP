#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include <limits>

class	Zombie {

public:
	Zombie(void);
	~Zombie(void);

	void	announce( void );
	void	add_name( std::string name );

private:
	std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif