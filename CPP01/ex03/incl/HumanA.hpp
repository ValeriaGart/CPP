#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weeapon );
		~HumanA();

		void    attack( void );

	private:
		Weapon&     _weapon;
		std::string _name;
		HumanA();

};