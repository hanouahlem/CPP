#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Intern intern;
	AForm *sform = intern.makeForm("shrubbery creation", "Garden");
	AForm *rform = intern.makeForm("robotomy request", "Human");
	AForm *pform = intern.makeForm("presidential pardon", "Prisoner");
	try
	{
		Bureaucrat a("Bureaucrat1", 1);
		Bureaucrat b("Bureaucrat150", 150);

		// AForm *errorForm = intern.makeForm("pardon", "Prisoner");

		std::cout << std::endl;
		b.signForm(*sform);
		b.signForm(*rform);
		std::cout << std::endl;

		// a.signForm(*errorForm);
		a.signForm(*sform);
		a.signForm(*rform);
		a.signForm(*pform);

		std::cout << std::endl;
		a.executeForm(*sform);
		a.executeForm(*rform);
		a.executeForm(*pform);
		std::cout << std::endl;

		b.executeForm(*sform);
		b.executeForm(*rform);
		b.executeForm(*pform);
		b.signForm(*pform);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		
	}
		delete sform;
		delete rform;
		delete pform;

	return 0;
}