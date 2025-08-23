#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp" 

class AForm;

class Bureaucrat
{
    private : 
            const std::string _Name;
            int _Grade;
    public :
            Bureaucrat();
            ~Bureaucrat();
            Bureaucrat(std::string name, int grade);
            Bureaucrat(const Bureaucrat &other);
            Bureaucrat &operator=(const Bureaucrat &other);

            std::string getName() const;
            int getGrade() const;

            void GradeUp();
            void GradeDown();
            void signForm(AForm &form);
            void executeForm(AForm const & form) const;

            class GradeTooHighException : public std::exception
            {
                public :  
                        virtual const char* what() const throw();
            };

            class GradeTooLowException : public std::exception
            {
                public :  
                        virtual const char* what() const throw();
            };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other);
#endif