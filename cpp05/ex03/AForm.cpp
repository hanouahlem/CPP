#include "AForm.hpp"

AForm::AForm() : _Name("Default"), _Signed(false), _GradeSigned(1), _GradeToExecut(1)
{
    std::cout << "Default constructor AForm called." << std::endl;
}

AForm::AForm(std::string name, int GrdSnd, int GrdToEx) : _Name(name), _Signed(false), _GradeSigned(GrdSnd), _GradeToExecut(GrdToEx)
{
    if (GrdSnd < 1 || GrdToEx < 1)
        throw (AForm::GradeTooHighException());
    else if(GrdSnd > 150 || GrdToEx > 150)
        throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &other) : _Name(getName()), _Signed(false), _GradeSigned(getGradeSigned()), _GradeToExecut(getGradeExecute())
{
    *this = other;
}


AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		_Signed = other._Signed;
	return *this;
}

bool AForm::beSigned(Bureaucrat Bureaucrat)
{
    if(_Signed)
        throw AlreadySigned();
    if(Bureaucrat.getGrade() <= this->_GradeSigned)
    {
        _Signed = true;
        return(true);
    }
    else
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
    return (this->_Name);
}

int AForm::getGradeSigned() const
{
    return (this->_GradeSigned);
}

int AForm::getGradeExecute() const
{
    return (this->_GradeToExecut);
}

bool AForm::getSigned() const
{
    if(_Signed == true)
        return true;
    return false;     
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
const char*	AForm::AlreadySigned::what() const throw()
{
	return ("AForm is already signed");
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return ("The Form is not signed");
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->_Signed == false)
		return (throw FormNotSigned());
	if (executor.getGrade() > _GradeSigned)
		throw AForm::GradeTooLowException();
	this->execute(executor);
}

std::ostream &operator<<(std::ostream &out, AForm const &other)
{
    out << "AForm name: " << other.getName() << std::endl;
    out << "Grade needed to sign: " << other.getGradeSigned() << std::endl;
    out << "Grade needed to execute: " << other.getGradeExecute() << std::endl;
    out << "Is Aform signed?: " << (other.getSigned() ? "Yes" : "No") << "." << std::endl;;
	return (out);
}
