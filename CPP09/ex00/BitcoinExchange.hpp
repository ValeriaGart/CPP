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
#include <ctime>

class	BitcoinExchange {

	public:
		BitcoinExchange ( std::string InputF );
		BitcoinExchange (BitcoinExchange const & to_copy);
		~BitcoinExchange( void );

		BitcoinExchange &	operator=(BitcoinExchange const & to_assign);

		std::string getInputfile(void) const ;
		void outputValues (void);
		std::map<std::string, double> getBitprices(void) const;

		class BitcoinError : public std::exception
        {
        	private:
        	    std::string _msg;
				BitcoinError(){return;};

        	public:
			BitcoinError(std::string msg) throw()
        	    {
        	        _msg = "Error has occurred... " + msg;
        	    }
        	    virtual const char* what() const throw()
        	    {
        	        return (_msg.c_str());
        	    }
        	    virtual ~BitcoinError() throw() {}
				BitcoinError(BitcoinError const & to_copy) throw()
				{
					*this = to_copy;
				}
				BitcoinError & operator=(BitcoinError const & to_assign) throw()
				{
					if (this != &to_assign)
						_msg = to_assign._msg;
					return (*this);
				}
    	};

	private:
		BitcoinExchange( void );
		std::string find_closest_date(const std::string& date); 
		std::map<std::string, double> loadBitcoinPrices(std::string BaseName);

		std::string _InputFile;
		std::map<std::string, double>	_bitPrices;
		void							ft_check_header(std::string line);
		bool							ft_check_date(std::string date);
		bool							ft_check_value(std::string valueStr);
		std::string						trim_spaces(std::string str);

};

#endif