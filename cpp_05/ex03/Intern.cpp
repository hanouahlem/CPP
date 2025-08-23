#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Form default constructor called" << std::endl;

}

Intern::~Intern()
{
    
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return(*this);
}

const char	*Intern::FormNotExist::what(void) const throw()
{
	return "Intern can't create form because it doesn't exist";
}

AForm *Intern::makeForm(const std::string name, const std::string target) const
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *Form;
    int i;
    for(i = 0; i < 3; i++)
    {
        if(name == forms[i])
            break;
    }
    switch (i)
    {
        case 0:
            Form = new ShrubberyCreationForm(target);
            std::cout << "Intern created shrubbery creation form" << std::endl;
            break;
        case 1:
            Form = new RobotomyRequestForm(target);
            std::cout << "Intern created Robotomy Reques form" << std::endl;
            break;
        case 2:
            Form = new PresidentialPardonForm(target);
            std::cout << "Intern created Presidential Pardon form" << std::endl;
            break;
        default:
            throw FormNotExist();
            break;
    }
    return(Form);
}
