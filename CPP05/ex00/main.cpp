#include "./incl/Bureaucrat.hpp"

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
    try {
        for (int i; i < 141; i++) {
            bur.decrementGrade();
            std::cout << bur << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}