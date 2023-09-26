/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:42:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/26 17:45:59 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "[ SHRUBBERY ] Constructor called" << std::endl;
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137) {
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == 0)
		throw(AForm::NotSignedException());
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
	return ("the file cannot be opened");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &s ) {
	std::cout << "[ SHRUBBERY ]  Assignement operator called" << std::endl;
	this->_target = s._target;
	return *this;
}