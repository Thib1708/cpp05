/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:43:44 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/08 11:43:48 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

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
		std::cout << "Throw exception when signed form\n" << std::endl;
		std::cout << WHITE;
		try
		{
			Bureaucrat	jean("Jean", 1);
			Bureaucrat	marcel("Marcel", 150);
			Form		a1("A1", 1, 30);
			Form		a69("A69", 69, 60);
			Form		a150("A150", 150, 90);
			std::cout << jean << std::endl;
			std::cout << marcel << std::endl;
			std::cout << a1 << std::endl;
			std::cout << a69 << std::endl;
			std::cout << a150 << std::endl;
			jean.signForm(a1);
			marcel.signForm(a69);
			jean.signForm(a69);
			marcel.signForm(a150);
			jean.signForm(a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return (0);
}