#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp" 
#include "Bureaucrat.hpp"
#include <fstream>
class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private :
            std::string _target;

    public :
            ShrubberyCreationForm();
            ShrubberyCreationForm(std::string target);
            ~ShrubberyCreationForm();
            ShrubberyCreationForm(const ShrubberyCreationForm &copy);
            ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
            std::string	getTarget() const;
            void execute(Bureaucrat const &executor) const;
            
            class OpenIsFailed : public std::exception
            {
                public :  
                        virtual const char* what() const throw();
            };
};

#endif