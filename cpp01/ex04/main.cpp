#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <string>
//./a.out talan ahlem

std::string replaceString(std::string str, std::string s1, std::string s2)
{
    size_t pos = 0;
    while((pos = str.find(s1, pos)) != std::string::npos)
    {
        str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
        pos += s2.length();
    }
    return(str);

}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::string str;

        std::ifstream fd(filename.c_str());
        if (!fd.is_open()) 
        {
            std::cout << "Impossible d'ouvrir le fichier" << std::endl;
            return 1;
        }

        std::ofstream outfile("replace");
            if (!outfile.is_open())
        {
            std::cout << "Impossible de créer le fichier de sortie" << std::endl;
            fd.close();
            return 1;
        }

        while(std::getline(fd,str))
        {
            str = replaceString(str, s1, s2);
            outfile << str << std::endl;
        }

        fd.close();
        outfile.close();
        return (0);
        
    }
    std::cout << "Please retry with 3 arguments " << std::endl;
    return (0);
}
