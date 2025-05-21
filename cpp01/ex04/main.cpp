#include <iostream>
#include <fcntl.h>
#include <fstream>
//./a.out talan ahlem

int main(int argc, char **argv)
{
    
    if (argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::ifstream fd(filename);
        
        fd.open(filename);
        return (0);
        
    }
    std::cout << "Please retry with 3 arguments " << std::endl;
    return (0);
}
