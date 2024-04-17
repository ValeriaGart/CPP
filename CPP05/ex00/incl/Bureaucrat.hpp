#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{

	public:
		Bureaucrat(Bureaucrat const & to_copy);
		Bureaucrat( const std::string& name, int grade );
		~Bureaucrat( void );

		Bureaucrat &	operator=(Bureaucrat const & to_assign);

		std::string getName() const;
		int         getGrade() const;
		void        incrementGrade();
		void        decrementGrade();
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too high";
				}
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too low";
				}
		};

	private:
		Bureaucrat( void );
		const	std::string _name;
		int					_grade;
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bur );

#endif