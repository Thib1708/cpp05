/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/06 14:27:12 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
	std::cout << "[ BUREAUCRAT ] Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "[ BUREAUCRAT ] Constructor called" << std::endl;
	this->_grade = grade;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[ BUREAUCRAT ] Destructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) {
	std::cout << "[ BUREAUCRAT ] Copied" << std::endl;
	*this = copy;
	return ;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &copy ) {
	std::cout << "[ BUREAUCRAT ]  Assignement operator called" << std::endl;
	this->_name = copy._name;
	this->_grade = copy._grade;
	return *this;
}

const std::string	&Bureaucrat::getName( void ) const {
	return this->_name;
}

const int	&Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void	Bureaucrat::upgrade( void ) {
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::downgrade( void ) {
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error: grade to high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error: grade to Low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}