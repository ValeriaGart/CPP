#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span& to_copy);
		Span& operator=(const Span& to_copy);
		~Span( void );

		void	addNumber(int num);
		void	addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		long	shortestSpan(void);
		long	longestSpan(void) const;
		void	putDeq(void);
		unsigned int	get_n(void)  const;
		std::deque<int>	get_vector(void)  const;
		class SpanException : public std::exception
		{
			private:
				std::string _msg;
			public:
				SpanException(std::string msg) throw()
				{
					_msg = "Span parser error...: " + msg ;
				}
				virtual const char* what() const throw()
				{
					return (_msg.c_str());
				}
				virtual ~SpanException() throw() {}
		};

	private:
		Span( void );
		unsigned int _n;
		std::deque<int>	_vector;
};

#endif