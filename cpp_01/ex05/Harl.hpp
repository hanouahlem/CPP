#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private:
        	std::string _level[4];                  
            void debug(void);
            void info(void);
            void warning(void);
            void error(void);

    public :
            Harl();
            ~Harl();
            void complain( std::string level);
};

#endif