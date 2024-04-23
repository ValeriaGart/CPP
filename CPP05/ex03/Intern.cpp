#include "./incl/Intern.hpp"

typedef Form *(*Formptr)(const std::string);

static Form *Shrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static Form *Robotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

static Form *Presidential(const std::string target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern( void ) {
	std::cout << "Intern constructor called" << std::endl;
	return ;
}

Intern::~Intern( void ) {
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &to_copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = to_copy;
}

Intern& Intern::operator=(const Intern &to_assign)
{
	(void)to_assign;
    std::cout << "Intern copy operator called" << std::endl;
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target) {
    Form *newform = NULL;

    const std::string form_names[] = { "shrubbery creation", "robotomy request", "presidential pardon"};

    Formptr forms_array[3] = {&Shrubbery, &Robotomy, &Presidential};

    for (size_t i = 0; i < 3; i += 1)
    {
        if (name == form_names[i])
        {
            std::cout << "Intern makes " << name << " form."<< std::endl;
            newform = forms_array[i](target);
            break ;
        }
    }
    if (!newform)
        std::cerr << "Intern couldn't create " << name << " form" << std::endl;
    return newform;
}
