#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(AForm const & to_copy);
		AForm( std::string name, std::string target, int signGrade, int execGrade);
		virtual ~AForm( void );

		AForm &	operator=(AForm const & to_assign);

		const std::string getName(void) const;
		const std::string		getTarget(void) const;
		bool	getSigned(void) const;
		int		getSignGrade(void) const;
		int		getExecuteGrade(void) const;
		
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const& bur) const;
	
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
		AForm( void );
		virtual void executeByForm(Bureaucrat const& bur) const = 0;
		const	std::string	_target;
		const	std::string _name;
		bool			    _signed;
        const int           _signGrade;
        const int           _executeGrade;
};

std::ostream&	operator<<( std::ostream& out, const AForm& form );

#endif