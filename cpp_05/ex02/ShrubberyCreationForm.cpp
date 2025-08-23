#include "ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII treesinside it.

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
    this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
    this->_target = target;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm default destructor called." << std::endl;

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    this->_target = other._target;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

const char* ShrubberyCreationForm::OpenIsFailed::what() const throw()
{
	return ("Open is failed !!");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{   
    std::ofstream out;
    if(executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    if(this->getSigned() == false)
        throw FormNotSigned();
    out.open((this->_target + "_shrubbery").c_str());
    if(!out.is_open())
        throw OpenIsFailed();
    out << "          " << std::endl;
    out << "    **     " << std::endl;
    out << "    /\\    " << std::endl;
    out << "   /**\\   " << std::endl;
    out << "  /****\\  " << std::endl;
    out << " /******\\ " << std::endl;
    out << "/********\\" << std::endl;
    out << "   ||||   " << std::endl;
    out << "   ||||   " << std::endl;
    out << "          " << std::endl;
    out.close();
}