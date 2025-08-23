#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class  PresidentialPardonForm : public AForm
{
    private :
            std::string _target;

    public :
            PresidentialPardonForm();
            PresidentialPardonForm(std::string _target);
            ~PresidentialPardonForm();
            PresidentialPardonForm(const PresidentialPardonForm &other);
            PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
            
            std::string	getTarget() const;
            void execute(Bureaucrat const & executor) const;

};

#endif