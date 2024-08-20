#include "./incl/Bureaucrat.hpp"

int     main( void ) {
    std::cout << "test_00\n" << std::endl;
    try {
        Bureaucrat bur("Mike", 120);

        for (int i; i < 141; i++) {
            bur.decrementGrade();
            std::cout << bur << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\ntest_01\n" << std::endl;
    try {
        Bureaucrat bur("Mike", 171);

        for (int i; i < 141; i++) {
            bur.decrementGrade();
            std::cout << bur << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}