#include "Span.hpp"

void Span::print() const
{
    for (size_t i = 0; i < _number.size(); i++)
        std::cout << _number[i] << " ";
    std::cout << std::endl;
}

int main()
{
    try
    {
        Span spn(5);
        spn.addNumber(5);
        spn.addNumber(2);
        spn.addNumber(10);
        spn.addNumber(25);
        spn.addNumber(1);
        std::cout << "Après ajout : ";
        spn.print();

        std::cout << "Shortest span: " << spn.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spn.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Span span(10); 
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        span.addMoreNumber(vec.begin(), vec.end());
        std::cout << "Après ajout du vector: ";
        span.print();
        
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test avec 10,000 nombres consécutifs ===" << std::endl;
    try 
    {
        Span sp(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; i++)
        {
            numbers.push_back(i); // 0, 1, 2, 3, ..., 9999
        }
        sp.addMoreNumber(numbers.begin(), numbers.end());
        // sp.print();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
