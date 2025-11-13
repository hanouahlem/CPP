#include "RPN.hpp"


void printfError(std::string error)
{
    std::cout << "Error" << error << std::endl;
}

static void whichSigne(const std::string& signe, std::stack<double>& stack)
{
    if (stack.size() < 2)
        return(printfError(" "));

    double b = stack.top() ; stack.pop();
    double a = stack.top() ; stack.pop();

    if (signe == "+")
        stack.push(a + b);
    else if (signe == "-")
        stack.push(a - b);
    else if (signe == "*")
        stack.push(a * b);
    else if (signe == "/")
    {
        if (b == 0)
            return;
        stack.push(a / b);
    }
}

void RPN::calculator(std::string input)
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
                return(printfError(": Number is bigger than 10"));
            stack.push(val);
        }
        else if (c == "+" || c == "-" || c == "*" || c == "/")
            whichSigne(c, stack);
        else
        {
            return(printfError(": Invalid character in expression"));
        }
    }
    if (stack.size() != 1)
        return(printfError(": Invalid RPN expression"));
    
    std::cout << stack.top() << std::endl;
}