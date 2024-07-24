#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange (BitcoinExchange const & to_copy) {
	*this = to_copy;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & to_assign) {
	if (this != &to_assign) {
		this->_InputFile = to_assign.getInputfile();
	}
	return *this;
}

std::string BitcoinExchange::getInputfile() const {
	return (this->_InputFile);
}

BitcoinExchange::BitcoinExchange ( std::string InputF ) : _InputFile(InputF) {


	_bitPrices = this->loadBitcoinPrices("data.csv");

	return;
}

void BitcoinExchange::outputValues() {
	std::ifstream file(this->_InputFile);
	std::string line, date, valueStr , pipe;
	double value;

	getline(file, line);
	while (getline(file, line)) {
		std::stringstream ss(line);
		getline(ss, date, ' ');
		getline(ss, pipe, ' ');
		if (pipe[0] != '|') {
			std::cerr << "Error: bad input => " << date << std::endl;
            continue;
		}
		if (!getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        try {
            value = stod(valueStr);
        } catch (const std::invalid_argument&) {
            std::cerr << "Error: invalid value for date " << date << ": " << valueStr << std::endl;
            continue;
        }
		if (valueStr.size() > 9 || value >  2147483647) {
			std::cerr << "Error: too large a number." << std::endl;
            continue;
		}
		const std::string& ndate = this->find_closest_date(date);
		double priceOnDate = _bitPrices.at(ndate);
		double bitcoinValue = value * priceOnDate;
		if (bitcoinValue < 0)
			std::cerr << ("Error: not a positive number.") << std::endl;
		else
			std::cout << ndate << " => " << value << " = " << std::fixed << std::setprecision(2) << bitcoinValue << std::endl;
	}
	file.close();
}

std::map<std::string, double> BitcoinExchange::loadBitcoinPrices(std::string BaseName) {
	
	std::map<std::string, double> bitPrices;
	std::ifstream file(BaseName);
	std::string new_line;
	std::string date;
	double price;

	getline(file, new_line);
	while (getline(file, new_line)) {
	    std::stringstream ss(new_line);
	    getline(ss, date, ',');
	    ss >> price;
	    bitPrices[date] = price;
	}
	file.close();
	return bitPrices;
}

std::string BitcoinExchange::find_closest_date(const std::string& date) {
	auto it = this->_bitPrices.lower_bound(date);

	if (it != _bitPrices.end() && it->first == date) {
	    return it->first;
	}

	if (it != _bitPrices.begin()) {
	    --it;
	}
	return it->first;
}
