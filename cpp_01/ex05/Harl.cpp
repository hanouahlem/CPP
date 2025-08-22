#include "Harl.hpp"

Harl::Harl()
{
    _level[0] = "DEBUG";
    _level[1] = "INFO";
    _level[2] = "WARNING";
    _level[3] = "ERROR";
}

Harl::~Harl()
{
 
}
void Harl::debug()
{
    std::cout << "{DEBUG} I love having extra bacon burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "{INFO} I cannot believe adding extra bacon costs more money" << std::endl;
}

void Harl::warning()
{
    std::cout << "{WARNING} I think I deserve to have some extra bacon for free" << std::endl;
}

void Harl::error()
{
    std::cout << "{ERROR} This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain( std::string level)
{
    void (Harl::*ptrF[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if(level == _level[i])
        {
            (this->*ptrF[i])();
            return;
        }
    }
    std::cout << "Your level does not exist. Please give me an other" << std::endl;

    return;
}