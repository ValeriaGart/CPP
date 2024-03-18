#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include <limits>

class	Zombie {

public:
	Zombie( std::string new_name );
	~Zombie(void);

	void announce( void );
	Zombie* newZombie( std::string name );
	void    randomChump( std::string name );

private:
	std::string	_name;
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif