#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp" 
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private : 
            std::string _target;

    public :
            RobotomyRequestForm();
            ~RobotomyRequestForm();
            RobotomyRequestForm(std::string target);
            RobotomyRequestForm(const RobotomyRequestForm &copy);
            RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
            std::string getTarget() const;
            void execute(Bureaucrat const & executor) const;

            class RobotomyFailed : public std::exception
            {
                public :  
                        virtual const char* what() const throw();
            };
};

#endif
