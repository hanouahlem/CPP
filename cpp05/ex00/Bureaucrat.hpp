#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class Bureaucrat
{
    private : 
            const std::string _Name;
            int _Grade;
    public :
        //     Bureaucrat();
            Bureaucrat(std::string name, int grade);
            ~Bureaucrat();
            Bureaucrat(const Bureaucrat &other);
            Bureaucrat &operator=(const Bureaucrat &other);

            std::string getName() const;
            int getGrade() const;

            void GradeUp();
            void GradeDown();

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