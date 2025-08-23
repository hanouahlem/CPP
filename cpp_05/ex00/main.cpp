#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat b1("Make", 1);
        std::cout << b1 << std::endl;
        b1.GradeUp();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Bureaucrat couldn't increment grade because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        Bureaucrat b2("Borice", 150);
        std::cout << b2 << std::endl;
        b2.GradeDown();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Bureaucrat couldn't decrement grade because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        Bureaucrat b3("Sam", 151);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Bureaucrat couldn't be created because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        Bureaucrat b4("David", 0);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Bureaucrat couldn't be created because: "<< e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        Bureaucrat b5("Lolo", 75);
        std::cout << b5 << std::endl;
        b5.GradeUp();
        std::cout << "After increment: " << b5 << std::endl;
        b5.GradeDown();
        std::cout << "After decrement: " << b5 << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }
    return 0;
}