/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/11 13:19:25 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm( void ) {
	std::cout << "[ AFORM ] Constructor called" << std::endl;
	this->_name = "Aform";
	this->_is_signed = 0;
	this->_grade_sign = 150;
	this->_grade_exec = 150;
	return ;
}

AForm::AForm( std::string name, int grade_sign, int grade_exec ): _name(name), _is_signed(0) {
	std::cout << "[ AFORM ] Constructor called" << std::endl;
	this->_grade_sign = grade_sign;
	this->_grade_exec = grade_exec;
	if (grade_sign < 1 || grade_exec < 1)
		throw(AForm::GradeTooHighException());
	if (grade_sign > 150 || grade_exec > 150)
		throw(AForm::GradeTooLowException());
	return ;
}
AForm::~AForm(void)
{
	std::cout << "[ AFORM ] Destructor called" << std::endl;
	return ;
}

AForm::AForm( const AForm &copy ) {
	std::cout << "[ AFORM ] Copied" << std::endl;
	*this = copy;
	return ;
}

AForm& AForm::operator=( const AForm &copy ) {
	std::cout << "[ AFORM ]  Assignement operator called" << std::endl;
	this->_grade_sign = copy._grade_sign;
	this->_is_signed = copy._is_signed;
	this->_name = copy._name;
	return *this;
}

const std::string	&AForm::getName( void ) const {
	return this->_name;
}

const int	&AForm::getSignGrade( void ) const {
	return this->_grade_sign;
}

const int	&AForm::getExecGrade( void ) const {
	return this->_grade_exec;
}

const bool	&AForm::getSigned( void ) const {
	return this->_is_signed;
}

void	AForm::beSigned( Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == 1)
		throw(AForm::AlreadySignedException());
	else
		this->_is_signed = 1;
	
}

void AForm::execute(Bureaucrat const & executor ) const {
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (this->_is_signed == 0)
		throw(AForm::NotSignedException());
	else
		this->executeForm(executor);
}


const char *AForm::AlreadySignedException::what(void) const throw()
{
	return ("AForm is already signed");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade is to high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade is to low");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("form is not signed");
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	return (str << form.getName() << ", signing grade : " << form.getSignGrade() << ", executing grade : " << form.getExecGrade());
}