#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

class	BitcoinExchange {

	public:
		BitcoinExchange ( std::string InputF );
		BitcoinExchange (BitcoinExchange const & to_copy);
		~BitcoinExchange( void );

		BitcoinExchange &	operator=(BitcoinExchange const & to_assign);

		std::string getInputfile(void) const ;
		void outputValues (void);

	private:
		BitcoinExchange( void );
		std::string find_closest_date(const std::string& date); 
		std::map<std::string, double> loadBitcoinPrices(std::string BaseName);

		std::string _InputFile;
		std::map<std::string, double> _bitPrices;

};

#endif