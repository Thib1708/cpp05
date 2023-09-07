/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/07 10:22:28 by thibaultgir      ###   ########.fr       */
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

void	Bureaucrat::signedForm( Form &form) {
	if (form.getSigned())
	{
		std::cout << form.getName() << " already signed" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade to high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade to low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)\
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}