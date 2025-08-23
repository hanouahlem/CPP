#include "PresidentialPardonForm.hpp"

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
    // std::cout << " PresidentialPardonForm construtor has called" << std::endl;
    this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
    this->_target = target;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
// std::cout << " PresidentialPardonForm destructor has called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    // std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
    this->_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    // std::cout << "Presidential Pardon Form assignment operator called" << std::endl;
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    if(this->getSigned() == false)
        throw FormNotSigned();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}