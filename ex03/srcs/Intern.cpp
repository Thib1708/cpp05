/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/08 11:32:13 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "[ INTERN ] Constructor called" << std::endl;
	return ;
}

Intern::~Intern( void ) {
	std::cout << "[ INTERN ] Destructor called" << std::endl;
	return ;
}

Intern::Intern( const Intern &copy ) {
	std::cout << "[ INTERN ] Copied" << std::endl;
	*this = copy;
	return ;
}

Intern& Intern::operator=( const Intern &copy ) {
	std::cout << "[ INTERN ]  Assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

Form *Intern::makeForm( std::string name, std::string target ) {
	std::string forms[3][2] = {
		{"shrubbery", "creation"}, 
		{"robotomy", "request"}, 
		{"presidential", "pardon"}
	};

	Form *createForm[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	std::string::size_type pos = 0;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	int i;
	int formIndex = -1;
	for (i = 0; i < 3; i++)
	{
		pos = name.find(forms[i][0]);
		if (pos != std::string::npos)
		{
			pos = name.find(forms[i][1]);
			if (pos != std::string::npos)
				formIndex = i;
		}
		if (formIndex != i) 
			delete (createForm[i]);
	}
	if (formIndex != -1)
		return (createForm[formIndex]);
	throw(Intern::InvalidNameFormException());
	return (NULL);
}

const char *Intern::InvalidNameFormException::what(void) const throw()
{
	return ("invalid form name");
}