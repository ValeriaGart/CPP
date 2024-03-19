#ifndef REPLACER_H
# define REPLACER_H

# include <iostream>
# include <limits>
# include <fstream>

class Replacer
{
	public:
		Replacer(std::string filename, std::string s1, std::string s2);
		~Replacer( void );
	
		bool	replace( void );

	private:
		std::string _filename;
		std::string _out_filename;
		std::string	_s1;
		std::string	_s2;
};


#endif