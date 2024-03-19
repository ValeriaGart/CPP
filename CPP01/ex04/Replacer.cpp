#include "incl/Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
{
	this->_filename 		= filename;
	this->_out_filename 	= this->_filename + ".replace";
	this->_s1				= s1;
	this->_s2				= s2;
	return ;
}

Replacer::~Replacer( void )
{
	std::cout << "Class destroyed (>‿◠)" << std::endl;
	return ;
}

bool	Replacer::replace( void ) {
	std::ifstream   input(this->_filename);
	std::string 	line;

    if (!input.is_open()) {
		std::cerr << "Unable to open the file" << std::endl;
        return (false);
	}
    if (std::getline(input, line, '\0')) {
		std::ofstream	output(this->_out_filename);
		size_t 			i = line.find(this->_s1);

		if (!output.is_open()) {
			input.close();
			std::cerr << "Unable to open out file:-((" << std::endl;
			return (false);
		}
		while ( i != std::string::npos ) {
			line.erase(i, this->_s1.length());
			line.insert(i, this->_s2);
			i = line.find(this->_s1);
		}
		output << line;
		output.close();
	}
    else {
    		std::cerr << "Empty file found." << std::endl;
			return (false);
	}
	input.close();
	return (true);
}