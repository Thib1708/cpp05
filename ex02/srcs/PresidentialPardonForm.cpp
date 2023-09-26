/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:54:13 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/26 17:46:17 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("Presidenial_Pardon_Form", 25, 5) {
	std::cout << "[ PRESIDENTIAL ] Constructor called" << std::endl;
	this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("Presidenial_Pardon_Form", 25, 5) {
	std::cout << "[ PRESIDENTIAL ] Constructor called" << std::endl;
	this->_target = "target";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[ PRESIDENTIAL ] Destructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &s ) {
	std::cout << "[ PRESIDENTIAL ] Copied" << std::endl;
	*this = s;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &s ) {
	std::cout << "[ PRESIDENTIAL ]  Assignement operator called" << std::endl;
	this->_target = s._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    (void)executor;
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == 0)
		throw(AForm::NotSignedException());
    std::cout << this->_target << ": you have been pardonned by Zaphod Beeblebrox" << std::endl;
}