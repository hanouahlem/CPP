#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
# include "AForm.hpp"

class Intern 
{
    private :

    public :
            Intern();
            ~Intern();
            Intern(const Intern &other);
            Intern &operator=(const Intern &other);
            AForm *makeForm(const std::string NameForm, const std::string target)const;
            class FormNotExist : public std::exception
            {
		        public:
			    virtual const char* what() const throw();
            };
};

#endif