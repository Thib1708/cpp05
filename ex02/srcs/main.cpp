/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:43:44 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 17:58:42 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	/* Throw exception when calling constructor with grade too high */
	{
		std::cout << BLUE;
		std::cout << "Throw exception when calling constructor with grade too high\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat mike("Mike", 0);
			std::cout << mike << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exception when calling constructor with grade too low */
	{
		std::cout << BLUE;
		std::cout << "Throw exception when calling constructor with grade too low\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat jim("Jim", 151);
			std::cout << jim << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Throw exeception when calling upgrade */
	{	
		std::cout << BLUE;
		std::cout << "Throw exeception when calling upgrade\n" << std::endl;
		std::cout << WHITE;
		try 
		{
			Bureaucrat dur("Dur", 3);
			std::cout << dur << std::endl;
			dur.upgrade();
			std::cout << dur << std::endl;
			dur.upgrade();
			std::cout << dur << std::endl;
			dur.upgrade();
			std::cout << dur << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exeception when calling downgrade */
	{	
		std::cout << BLUE;
		std::cout << "Throw exeception when calling downgrade\n" << std::endl;
		std::cout << WHITE;
		try 
		{
			Bureaucrat alan("Alan", 149);
			std::cout << alan << std::endl;
			alan.downgrade();
			std::cout << alan << std::endl;
			alan.downgrade();
			std::cout << alan << std::endl;
			alan.downgrade();
			std::cout << alan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Throw exception when signed form */
	{
		std::cout << BLUE;
		std::cout << "Throw exception when signing form\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			RobotomyRequestForm	a72("Tree");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a72 << std::endl;
			marcel.signForm(a72);
			jean.signForm(a72);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Throw exception when signed form */
	{
		std::cout << BLUE;
		std::cout << "Throw exception when signing form already signed\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 2);
			PresidentialPardonForm	a1("Tibo");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.signForm(a1);
			marcel.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Throw exception when executing form\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			PresidentialPardonForm	a1("Tibo");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			marcel.signForm(a1);
			jean.executeForm(a1);
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Throw exception when executing form not signed\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			PresidentialPardonForm	a1("Tibo");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.executeForm(a1);
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Throw exception if the file can't be opened \n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			ShrubberyCreationForm	a1("tree");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Executing ShrubberyCreationForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			ShrubberyCreationForm	a1("tree1");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Executing RobotomyRequestForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			RobotomyRequestForm	a1("Tibo");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Executing PresidentialPardonForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			PresidentialPardonForm	a1("Tibo");
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			jean.signForm(a1);
			jean.executeForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}