#include "./incl/AForm.hpp"
#include "./incl/Bureaucrat.hpp"
#include "./incl/PresidentialPardonForm.hpp"
#include "./incl/RobotomyRequestForm.hpp"
#include "./incl/ShrubberyCreationForm.hpp"
#include <cstdlib>

int     main( void ) {
    Bureaucrat mike("Mike", 10);
    std::cout << mike;
	Bureaucrat nick("Nick", 150);
    std::cout << nick;
	std::cout << std::endl;

	ShrubberyCreationForm scf("Noah");
    std::cout << scf << std::endl;
	PresidentialPardonForm ppf("Noah");
    std::cout << ppf << std::endl;
	RobotomyRequestForm rrf("Noah");
    std::cout << rrf << std::endl;
	std::cout << std::endl;

    try {
	    mike.executeForm(scf);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
	    nick.executeForm(scf);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
	scf.beSigned(mike);
    mike.executeForm(scf);
    std::cout << std::endl;


    try {
	    mike.executeForm(ppf);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat pedro("Pedro", 1);
    std::cout << pedro;
    pedro.executeForm(ppf);
	ppf.beSigned(pedro);
	pedro.executeForm(ppf);
    std::cout << std::endl;


	mike.executeForm(rrf);
    try {
        rrf.beSigned(nick);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    rrf.beSigned(mike);
    mike.executeForm(rrf);
    try {
        nick.executeForm(rrf);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    return (0);
}