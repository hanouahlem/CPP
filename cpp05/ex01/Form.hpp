#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private : 
            const std::string _Name;
            bool _Signed;
            const int _GradeSigned;
            const int _GradeToExecut;
    public :
            Form();
            Form(std::string name,int GrdSnd, int GrdToEx);
            ~Form();
            Form(const Form &other);
            Form &operator=(const Form &other);

            std::string getName() const;
            int getGradeSigned() const;
            int getGradeExecute() const;
            bool getSigned() const;
            bool beSigned(Bureaucrat Bureaucrat);

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
			const char	*what(void) const throw();
            };
};

std::ostream &operator<<(std::ostream &out, Form const &other);

#endif