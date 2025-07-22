#include "Form.hpp"

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

Form::Form(const Form &other)
{
    this->
}


Form &Form::operator=(Form const &copy)
{
	if (this != &copy)
		_Signed = copy._Signed;
	return *this;
}
// void Form::beSigned(Bureaucrat Bureaucrat)
// {
//     if(_Signed)
//     std::cout << "signed" << std::endl;
//     if(Bureaucrat.getGrade() > _GradeSigned)
//         throw Form::GradeTooLowException();
// }
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
                
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
