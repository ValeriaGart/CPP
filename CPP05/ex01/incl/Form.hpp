#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form {
	public:
		Form(Form const & to_copy);
		Form( const std::string& name, int grade );
		~Form( void );

		Form &	operator=(Form const & to_assign);
        	std::string getName() const;
		int         getGrade() const;
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