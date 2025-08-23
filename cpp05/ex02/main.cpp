#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Bureaucrat1", 1);
		Bureaucrat b("Bureaucrat150", 150);
		ShrubberyCreationForm GardenForm("Garden");
		RobotomyRequestForm   MikeForm("Mike");
		PresidentialPardonForm LufyForm("Lufy");
		std::cout << std::endl;

		b.signForm(GardenForm);
		b.signForm(MikeForm);
		a.executeForm(GardenForm);
		std::cout << std::endl;


		a.signForm(GardenForm);
		a.signForm(MikeForm);
		a.signForm(LufyForm);
		a.executeForm(GardenForm);
		a.executeForm(MikeForm);
		a.executeForm(LufyForm);
		std::cout << std::endl;


		b.executeForm(GardenForm);
		b.executeForm(MikeForm);
		b.executeForm(LufyForm);
		b.signForm(LufyForm);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}