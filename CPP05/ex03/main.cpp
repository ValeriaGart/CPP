#include "./incl/Form.hpp"
#include "./incl/Intern.hpp"
#include "./incl/Bureaucrat.hpp"
#include "./incl/PresidentialPardonForm.hpp"
#include "./incl/RobotomyRequestForm.hpp"
#include "./incl/ShrubberyCreationForm.hpp"
#include <cstdlib>

int     main( void ) {
    
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    delete(rrf);
    return (0);
}