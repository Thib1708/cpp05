/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/08 13:03:58 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form( void ) {
	std::cout << "[ FORM ] Constructor called" << std::endl;
	this->_name = "form";
	this->_is_signed = 0;
	this->_grade_sign = 150;
	this->_grade_exec = 150;
	return ;
}

Form::Form( std::string name, int grade_sign, int grade_exec ): _name(name), _is_signed(0) {
	std::cout << "[ FORM ] Constructor called" << std::endl;
	this->_grade_sign = grade_sign;
	this->_grade_exec = grade_exec;
	if (grade_sign < 1 || grade_exec < 1)
		throw(Form::GradeTooHighException());
	if (grade_sign > 150 || grade_exec > 150)
		throw(Form::GradeTooLowException());
	return ;
}
Form::~Form(void)
{
	std::cout << "[ FORM ] Destructor called" << std::endl;
	return ;
}

Form::Form( const Form &copy ) {
	std::cout << "[ FORM ] Copied" << std::endl;
	*this = copy;
	return ;
}

Form& Form::operator=( const Form &copy ) {
	std::cout << "[ FORM ]  Assignement operator called" << std::endl;
	this->_grade_sign = copy._grade_sign;
	this->_is_signed = copy._is_signed;
	this->_name = copy._name;
	return *this;
}

const std::string	&Form::getName( void ) const {
	return this->_name;
}

const int	&Form::getGrade( void ) const {
	return this->_grade_sign;
}

const bool	&Form::getSigned( void ) const {
	return this->_is_signed;
}

void	Form::beSigned( Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw(Form::GradeTooLowException());
	else 
		this->_is_signed = 1;
	
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade is to high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade is to low");
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	return (str << form.getName() << ", form grade " << form.getGrade());
}