#include "./incl/Form.hpp"

int     main( void ) {
    Bureaucrat bur("Mike", 10);

    /*try {
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
        std::cout << bur << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }*/
    /*try {
        for (int i; i < 141; i++) {
            bur.decrementGrade();
            std::cout << bur << std::endl;
        }
    }
   catch (std::exception & e) {
        std::cout << e.what() << std::endl; 
    }*/

    try {
        Form form1("form1", 10, 10);
        form1.beSigned(bur);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form form2("form2", 11, 10);
        form2.beSigned(bur);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form form3("form3", 0, 10);
        form3.beSigned(bur);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form form4("form4", 150, 10);
        form4.beSigned(bur);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form form5("form5", 151, 10);
        form5.beSigned(bur);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}