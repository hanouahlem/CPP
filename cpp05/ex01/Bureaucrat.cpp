#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade)
{
    // std::cout << "Constructor has called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
    // std::cout << "Destructor has called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _Name(other.getName())
{
    this->_Grade = other.getGrade();
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->_Grade = other._Grade;
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return (this->_Name);
}

int Bureaucrat::getGrade() const
{
    return (this->_Grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

void Bureaucrat::GradeUp()
{
    if (this->_Grade - 1 < 1) 
        throw Bureaucrat::GradeTooHighException();
    else
        this->_Grade--;
}

void Bureaucrat::GradeDown()
{
    if (this->_Grade + 1 > 150) 
        throw Bureaucrat::GradeTooLowException();
    else
        this->_Grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other)
{
    out << other.getName() << ", bureaucrat garde " << other.getGrade() << ".";
    return (out);
}