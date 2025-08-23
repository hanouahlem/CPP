#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private : 
            const std::string _Name;
            bool _Signed;
            const int _GradeSigned;
            const int _GradeToExecut;
    public :
            AForm();
            AForm(std::string name,int const GrdSnd, int const GrdToEx);
            ~AForm();
            AForm(const AForm &other);
            AForm &operator=(const AForm &other);

            std::string getName() const;
            int getGradeSigned() const;
            int getGradeExecute() const;
            bool getSigned() const;
            bool beSigned(Bureaucrat Bureaucrat);
            virtual void execute(Bureaucrat const & executor) const = 0;

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
            class AlreadySigned : public std::exception
            {
		public:
			virtual const char *what(void) const throw();
            };
                        
            class FormNotSigned : public std::exception
            {
                public :  
                        virtual const char* what() const throw();
            };
};

std::ostream &operator<<(std::ostream &out, AForm const &other);

#endif