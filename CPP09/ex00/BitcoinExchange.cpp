#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange (BitcoinExchange const & to_copy) {
	if (this !=  &to_copy) {
		*this = to_copy;
		this->_InputFile =  to_copy.getInputfile();
		this->_bitPrices = to_copy.getBitprices();
	}
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & to_assign) {
	if (this != &to_assign) {
		this->_InputFile = to_assign.getInputfile();
		this->_bitPrices = to_assign.getBitprices();
	}
	return *this;
}

std::string BitcoinExchange::getInputfile() const {
	return (this->_InputFile);
}

std::map<std::string, double> BitcoinExchange::getBitprices(void) const{
	return (this->_bitPrices);
}

BitcoinExchange::BitcoinExchange ( std::string InputF ) : _InputFile(InputF) {

	_bitPrices = this->loadBitcoinPrices("data.csv");

	return;
}

void BitcoinExchange::outputValues() {
	std::ifstream file(this->_InputFile);

	if (!file) {
		throw BitcoinError("InputFile can't be opened!");
	}
	std::string line, date, valueStr;
	float value;

	std::getline(file, line);
	ft_check_header(line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		if (line.find('|') == std::string::npos) {
			std::cerr << "Error: bad input. Wrong syntax" << std::endl;
			continue;
		}
		std::getline(ss, date, '|');
		if (ft_check_date(date) == false) {
            continue;
		}

		std::getline(ss, valueStr);
		if (ft_check_value(valueStr) == false) { 
			continue;
		}
		value = std::stof(valueStr);

		const std::string& ndate = this->find_closest_date(date);
		double priceOnDate = _bitPrices.at(ndate);
		double bitcoinValue = value * priceOnDate;
		std::cout << ndate << " => " << value << " = " << std::fixed << std::setprecision(2) << bitcoinValue << std::endl;
	}
	file.close();
}

std::string BitcoinExchange::trim_spaces(std::string str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			str = str.substr(1);
			--i;
		}
		if (str[i] != ' ') {
			break;
		}
	}

	for (size_t i = str.length() - 1; i >= 0 ; --i) {
		if (str[i] == ' ') {
			str.erase(str.length() - 1);
		}
		if (str[i] != ' ') {
			break;
		}
	}
	return str;
}

bool	BitcoinExchange::ft_check_value(std::string valueStr) {

	valueStr = trim_spaces(valueStr);
	for (size_t i = 0; i < valueStr.length(); ++i) {
		if (valueStr[i] == '0' && (i + 1 < valueStr.length() && valueStr[i + 1] != '.')) {
			valueStr = valueStr.substr(1);
			--i;
		}
		if (valueStr[i] != '0') {
			break;
		} 
	}

	if (valueStr.empty()) {
		std::cerr << "Error: Empty value" << std::endl;
		return false;
	}
	bool hasDecimal = false;
	for (size_t i = 0; i < valueStr.length(); ++i) {
		if (!isdigit(valueStr[i]) && valueStr[i] != '.') {
			std::cerr << "Error: bad input. Wrong value syntax" << std::endl;
			return false;
		}
		if (valueStr[i] == '.') {
			if (hasDecimal == true) {
				std::cerr << "Error: bad input. Wrong value syntax" << std::endl;
				return false;
			}
			if (i == 0 || i == valueStr.length() - 1) {
				std::cerr << "Error: bad input. Wrong value syntax" << std::endl;
				return false;
			}
			if (i > 4) {
				std::cerr << "Error: bad input. too large a number" << std::endl;
				return false;
			}
			hasDecimal = true;
		}
	}

	if (hasDecimal == false && valueStr.length() > 4) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}

	float value = std::stof(valueStr);
	if (value > 1000) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}

	return true;
}

bool	BitcoinExchange::ft_check_date(std::string date) {

	date = trim_spaces(date);


	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << "Error: bad input. Wrong syntax " << std::endl;
		return false;
	}
	
	for (size_t i = 0; i < date.length(); ++i) {
		if ((i == 4 || i == 7) && date[i] != '-')
	{	std::cerr << "Error: bad input. Wrong syntax " << std::endl;
		return false;
	}
		else if (!isdigit(date[i]) && i != 4 && i != 7)
		{	std::cerr << "Error: bad input. Wrong syntax " << std::endl;
			return false;
		}
	}

	int yearInt = std::stoi(date.substr(0, 4));
	int monthInt = std::stoi(date.substr(5, 2));
	int dayInt = std::stoi(date.substr(8, 2));

	if (yearInt < 2008 || yearInt > 2024)
	{	std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (monthInt < 1 || monthInt > 12)
	{	std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (dayInt < 1 || dayInt > 31)
	{	std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
	{	std::cerr << "Error: bad input => " << date  << std::endl;
		return false;
	}
	if (monthInt == 2) {
		if (dayInt > 29 || (dayInt == 29 && !(yearInt % 4 == 0 ))) {
			std::cerr << "Error: bad input => " << date << std::endl;
			return false;
		}
	}

	return true;
}

void BitcoinExchange::ft_check_header(std::string line) {
	std::string header = "";
	for (size_t i = 0; i < line.length(); ++i) {
		if (line[i] != ' ') {
			header += line[i];
		}
	}
	if (header != "date|value") {
		throw BitcoinError("Data.csv. Header is not valid!");
	}
}

std::map<std::string, double> BitcoinExchange::loadBitcoinPrices(std::string BaseName) {
	
	std::map<std::string, double> bitPrices;
	std::ifstream file(BaseName);

	if (!file) {
		throw BitcoinError("Data.csv can't be opened!");
	}

	std::string new_line;
	std::string date;
	double price;

	std::getline(file, new_line);
	while (std::getline(file, new_line)) {
	    std::stringstream ss(new_line);
	    std::getline(ss, date, ',');
	    ss >> price;
	    bitPrices[date] = price;
	}
	file.close();
	return bitPrices;
}

std::string BitcoinExchange::find_closest_date(const std::string& date) {
	
	std::map<std::string, double>::iterator it = this->_bitPrices.lower_bound(date);

    if (it != _bitPrices.end() && it->first == date) {
        return it->first;
    }

    if (it != _bitPrices.begin()) {
        --it;
    }

    return it->first;
}
