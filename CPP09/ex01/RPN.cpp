#include "RPN.hpp"

RPN::~RPN( void ) {}

RPN::RPN( void ) {}

RPN::RPN(const RPN &src) {
	if (this != &src) {
		*this = src;
		this->_stack = src.getStack();
	}
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		this->_stack = src.getStack();
	}
	return *this;
}

std::vector<int> RPN::getStack() const {
	return this->_stack;
}

bool RPN::_is_operator(const std::string &token) {
	if (token == "+" || token == "-" || token == "*" || token == "/") {
		return true;
	} else {
		return false;
	}
}

int RPN::_operate(int a, int b, const std::string &op) {
    if (op == "+") {
		return a + b;}
    if (op == "-") {
		return a - b;}
    if (op == "*") {
		return a * b;}
    if (op == "/") {
        if (b == 0) {
            throw RPN::RPNError("Division by zero");}
        return a / b;
    }
    return 0;
}

 RPN::RPN(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (_is_operator(token)) {
            if (this->_stack.size() < 2) {
                throw RPNError("Not enough operands for operation: " + token);}
            int b = this->_stack.back();
            this->_stack.pop_back();
            int a = this->_stack.back();
            this->_stack.pop_back();
            this->_stack.push_back(_operate(a, b, token));
        } else {
            char *endptr;
            if (token.length() == 0) {
                continue;}
            if (token.length() > 1 || token[0] < '0' || token[0] > '9') {
                throw RPNError("Invalid token: " + token);}
            int num = std::strtol(token.c_str(), &endptr, 10);
            if (*endptr != '\0') {
                throw RPNError("Invalid token: " + token);}
            this->_stack.push_back(num);
        }
    }

    if (this->_stack.size() != 1) {
        throw RPNError("Invalid expression: " + expression);}
}

std::ostream&	operator<<( std::ostream& out, const RPN& rpn )
{
	std::vector<int> stack = rpn.getStack();
	std::vector<int>::iterator it = stack.begin();
	for(; it != stack.end(); ++it) {
		out << *it;
		if (it + 1 != stack.end()) {
			out << " ";
		}
	}
	out << std::endl;
	return (out);
}