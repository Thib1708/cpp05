/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:43:44 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 18:00:35 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	{
		std::cout << BLUE;
		std::cout << "Create ShrubberyCreationForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Intern tibo;
			AForm *form;
			form = tibo.makeForm("shrubbery creation", "garden");
			Bureaucrat	jean("Jean", 1);
			std::cout << jean << std::endl;
			std::cout << *form << std::endl;
			jean.signForm(*form);
			jean.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Create RobotomyRequestForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Intern tibo;
			AForm *form;
			form = tibo.makeForm("robotomy_request", "Will");
			Bureaucrat	jean("Jean", 1);
			std::cout << jean << std::endl;
			std::cout << *form << std::endl;
			jean.signForm(*form);
			jean.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Create PresidentialPardonForm\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Intern tibo;
			AForm *form;
			form = tibo.makeForm("presidential-pardon", "Will");
			Bureaucrat	jean("Jean", 1);
			std::cout << jean << std::endl;
			std::cout << *form << std::endl;
			jean.signForm(*form);
			jean.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		std::cout << BLUE;
		std::cout << "Create PresidentialPardonForm failure\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Intern tibo;
			AForm *form;
			form = tibo.makeForm("presidential unknow", "Will");
			Bureaucrat	jean("Jean", 1);
			std::cout << jean << std::endl;
			std::cout << *form << std::endl;
			jean.signForm(*form);
			jean.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}