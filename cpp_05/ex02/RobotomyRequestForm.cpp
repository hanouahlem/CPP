#include "RobotomyRequestForm.hpp"

// Required grades: sign 72, exec 45
// has been robotomized successfully

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
    this->_target = "Defaul";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
    this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    this->_target = other._target;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
const char*	RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("the robotomy failed");
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::srand(std::time(0)); // Initialiser le générateur de nombres aléatoires
    if(executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    if(this->getSigned() == false)
        throw FormNotSigned();
    std::cout << _target << " Bzzzzzzzzzz… Vrrrrrrr… bzzzzzzzzzz…" << std::endl;
    if(std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        throw RobotomyFailed();
}


// On initialise le generateur de nombres aleatoires avec l heure actuelle.
// Ça permet que le resultat soit different à chaque execution.