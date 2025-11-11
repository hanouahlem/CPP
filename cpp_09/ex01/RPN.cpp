#include "RPN.hpp"


static void whichSigne(const std::string& signe, std::stack<double>& stack)
{
    if (stack.size() < 2)
        throw std::invalid_argument("Error: Not enough, please make any more number");

    double b = stack.top();
    stack.pop();
    double a = stack.top();
    stack.pop();

    if (signe == "+")
        stack.push(a + b);
    else if (signe == "-")
        stack.push(a - b);
    else if (signe == "*")
        stack.push(a * b);
    else if (signe == "/")
    {
        if (b == 0)
            throw std::invalid_argument("Error: Division by zero is not possible");
        stack.push(a / b);
    }
}

double RPN::calculator(std::string input)
{
    std::stack<double> stack;
    std::string c;
    std::stringstream str(input);

    while(getline(str, c, ' '))
    {
        if(c.empty())
            continue;
        double val = std::strtod(c.c_str(), NULL);
        if(c >= "0" && c <= "9")
        {
            if(val > 10)
                throw std::invalid_argument("Error: Number is bigger than 10");
            stack.push(val);
        }
        else if (c == "+" || c == "-" || c == "*" || c == "/")
            whichSigne(c, stack);
    }
    return stack.top();
}