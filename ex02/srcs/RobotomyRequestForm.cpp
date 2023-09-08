/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:53:24 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/07 19:06:48 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("RobotomyRequestFrom", 72, 45) {
	std::cout << "[ ROBOTOMY ] Constructor called" << std::endl;
	this->_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RobotomyRequestFrom", 72, 45) {
	std::cout << "[ ROBOTOMY ] Constructor called" << std::endl;
	this->_target = "target";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[ ROBOTOMY ] Destructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &s ) {
	std::cout << "[ ROBOTOMY ] Copied" << std::endl;
	*this = s;
	return ;
}

void RobotomyRequestForm::executeForm(Bureaucrat const &executor) const {
	srand (time(NULL));

	std::cout << "***drill sound***" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " you were successfully robotised" << std::endl;
	else 
		std::cout << "Failure" << std::endl;
	(void)executor;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &s ) {
	std::cout << "[ ROBOTOMY ]  Assignement operator called" << std::endl;
	this->_target = s._target;
	return *this;
}