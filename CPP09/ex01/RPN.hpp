#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <string>

class RPN
{
	public:
		RPN(const std::string &expression);
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &src);

		std::vector<int> getStack() const;

		class RPNError : public std::exception
        {
        	private:
        	    std::string _msg;
				RPNError(){return;};
				RPNError(RPNError const & to_copy) throw()
				{
					*this = to_copy;
				}
				RPNError & operator=(RPNError const & to_assign) throw()
				{
					if (this != &to_assign)
						_msg = to_assign._msg;
					return (*this);
				}

        	public:
				RPNError(std::string msg) throw()
        	    {
        	        _msg = "Error has occurred... " + msg;
        	    }
        	    virtual const char* what() const throw()
        	    {
        	        return (_msg.c_str());
        	    }
        	    virtual ~RPNError() throw() {}
    	};

	private:
		RPN();

		bool _is_operator(const std::string &token);
		int _operate(int a, int b, const std::string &op);

		std::vector<int> _stack;
};

std::ostream&	operator<<( std::ostream& out, const RPN& rpn );


#endif