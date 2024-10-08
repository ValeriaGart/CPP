#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form(Form const & to_copy);
		Form( std::string name, int signGrade, int execGrade);
		~Form( void );

		Form &	operator=(Form const & to_assign);

		const std::string getName(void) const;
		bool	getSigned(void) const;
		int		getSignGrade(void) const;
		int		getExecuteGrade(void) const;
		
		void beSigned(Bureaucrat &bureaucrat);
	
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
		Form( void );
		const	std::string _name;
		bool			    _signed;
        const int           _signGrade;
        const int           _executeGrade;
};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif