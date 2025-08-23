#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat b1("Mike", 5);
        Form f1("David", 10, 50);

        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << std::endl;
        std::cout << f1 << std::endl;
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b2("Marlo", 50);
        Form f2("Denver", 30, 50);

        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Form f3("Invalid Form", 151, 50);
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Form couldn't be created: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b3("Moussa", 1);
        Form f4("Yanis", 5, 10);

        b3.signForm(f4);
        b3.signForm(f4);
    } 
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}