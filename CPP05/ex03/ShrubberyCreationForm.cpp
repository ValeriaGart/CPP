#include "./incl/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", target, 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called. Target:" << target << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy)
: Form(to_copy.getName(), to_copy.getTarget(), to_copy.getSignGrade(), to_copy.getExecuteGrade()) {
	std::cout << "ShrubberyCreationForm copy constructor called. Target:" << this->getTarget() << std::endl;
	*this = to_copy;
}


ShrubberyCreationForm::ShrubberyCreationForm( void )
: Form("ShrubberyCreationForm", "target", 145, 137) {
	return ;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called. Target:" << this->getTarget() << std::endl;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &to_assign) {
	std::cout << "ShrubberyCreationForm copy operator called. Target:" << this->getTarget() << std::endl;
	if (this == &to_assign)
		return *this;
	return *this;
}

void ShrubberyCreationForm::executeByForm(Bureaucrat const& bur) const
{
	if (bur.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cerr	<< "ShrubberyCreationForm couldn't be executed by "
					<< bur.getName() << " because it was not signed" << std::endl;
	else
	{
		std::ofstream out((this->getTarget() + "_shrubbery"));

		if (!out.is_open()) {
			std::cerr << "Unable to open out file:-((" << std::endl;
			return;
		}

		std::cout << "ShrubberyCreationForm form being executed..." << std::endl;

		out << "\n"
			<< "                                            ." << "\n"
			<< "                                    .         ;  " << "\n"
			<< "       .              .              ;%     ;;   " << "\n"
			<< "         ,           ,                :;%  %;   " << "\n"
			<< "          :         ;                   :;%;'     .,   " << "\n"
			<< " ,.        %;     %;            ;        %;'    ,;" << "\n"
			<< "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << "\n"
			<< "    %;       %;%;      ,  ;       %;  ;%;   ,%;' " << "\n"
			<< "     ;%;      %;        ;%;        % ;%;  ,%;'" << "\n"
			<< "      `%;.     ;%;     %;'         `;%%;.%;'" << "\n"
			<< "       `:;%.    ;%%. %@;        %; ;@%;%'" << "\n"
			<< "          `:%;.  :;bd%;          %;@%;'" << "\n"
			<< "            `@%:.  :;%.         ;@@%;'   " << "\n"
			<< "              `@%.  `;@%.      ;@@%;         " << "\n"
			<< "                `@%%. `@%%    ;@@%;        " << "\n"
			<< "                  ;@%. :@%%  %@@%;       " << "\n"
			<< "                    %@bd%%%bd%%:;     " << "\n"
			<< "                      #@%%%%%:;;" << "\n"
			<< "                      %@@%%%::;" << "\n"
			<< "                      %@@@%(o);  . '         " << "\n"
			<< "                      %@@@o%;:(.,'         " << "\n"
			<< "                  `.. %@@@o%::;         " << "\n"
			<< "                     `)@@@o%::;         " << "\n"
			<< "                      %@@(o)::;        " << "\n"
			<< "                     .%@@@@%::;         " << "\n"
			<< "                     ;%@@@@%::;.          " << "\n"
			<< "                    ;%@@@@%%:;;;. " << "\n"
			<< "                ...;%@@@@@%%:;;;;,..   " << std::endl;
		}
}