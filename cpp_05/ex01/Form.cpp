#include "Form.hpp"

Form::Form() : _Name("Default"), _Signed(false), _GradeSigned(1), _GradeToExecut(1)
{
    // std::cout << "Form: Default constructor called." << std::endl;
}

Form::Form(std::string name, int GrdSnd, int GrdToEx) : _Name(name), _Signed(false), _GradeSigned(GrdSnd), _GradeToExecut(GrdToEx)
{
    if (GrdSnd < 1 || GrdToEx < 1)
        throw (Form::GradeTooHighException());
    else if(GrdSnd > 150 || GrdToEx > 150)
        throw (Form::GradeTooLowException());
}

Form::~Form()
{

}

Form::Form(const Form &other) : _Name(other.getName()), _Signed(false), _GradeSigned(other.getGradeSigned()), _GradeToExecut(other.getGradeExecute())
{
    *this = other;
}


Form &Form::operator=(Form const &copy)
{
	if (this != &copy)
		_Signed = copy._Signed;
	return *this;
}

bool Form::beSigned(Bureaucrat Bureaucrat)
{
    if(_Signed)
        throw AlreadySigned();
    if(Bureaucrat.getGrade() <= this->_GradeSigned)
    {
        _Signed = true;
        return(true);
    }
    else
        throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
    return (this->_Name);
}

int Form::getGradeSigned() const
{
    return (this->_GradeSigned);
}

int Form::getGradeExecute() const
{
    return (this->_GradeToExecut);
}

bool Form::getSigned() const
{
    if(_Signed == true)
        return true;
    return false;     
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
const char*	Form::AlreadySigned::what() const throw()
{
	return ("Form is already signed");
}

std::ostream &operator<<(std::ostream &out, Form const &other)
{
    out << "Form name: " << other.getName() << std::endl;
    out << "Grade needed to sign: " << other.getGradeSigned() << std::endl;
    out << "Grade needed to execute: " << other.getGradeExecute() << std::endl;
    out << "Is form signed?: " << (other.getSigned() ? "Yes" : "No") << "." << std::endl;;
	return (out);
}