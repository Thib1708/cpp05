/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:42:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/08 09:57:30 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("ShrubberyCreationForm", 145, 137) {
	std::cout << "[ SHRUBBERY ] Constructor called" << std::endl;
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreationForm", 145, 137) {
	std::cout << "[ SHRUBBERY ] Constructor called" << std::endl;
	this->_target = "target";
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[ SHRUBBERY ] Destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &s ) {
	std::cout << "[ SHRUBBERY ] Copied" << std::endl;
	*this = s;
	return ;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const &executor) const {
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	if (file.fail())
		throw(ShrubberyCreationForm::CantOpenFileException());
	file << "		      &&& &&  & &&" << std::endl;
	file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "     &&     \\|||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "       , -=-~  .-^- _" << std::endl;
	file.close();
	(void)executor;
}

const char *ShrubberyCreationForm::CantOpenFileException::what(void) const throw()
{
	return ("can't open file");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &s ) {
	std::cout << "[ SHRUBBERY ]  Assignement operator called" << std::endl;
	this->_target = s._target;
	return *this;
}