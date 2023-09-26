/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 17:57:07 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form( void ): _name("Form"), _grade_sign(150), _grade_exec(150) {
	std::cout << "[ FORM ] Constructor called" << std::endl;
	this->_is_signed = 0;
	return ;
}

Form::Form( std::string name, int grade_sign, int grade_exec ): 
	_name(name), 
	_is_signed(0), 
	_grade_sign(grade_sign),
 	_grade_exec(grade_exec) 
{
	std::cout << "[ FORM ] Constructor called" << std::endl;
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

Form::Form( const Form &copy ):
	_name(copy.getName()), 
	_is_signed(copy.getSigned()), 
	_grade_sign(copy.getSignGrade()),
 	_grade_exec(copy.getExecGrade()) 
{
	std::cout << "[ FORM ] Copied" << std::endl;
	*this = copy;
	return ;
}

Form& Form::operator=( const Form &copy ) {
	std::cout << "[ FORM ]  Assignement operator called" << std::endl;
	this->_is_signed = copy._is_signed;
	return *this;
}

const std::string	&Form::getName( void ) const {
	return this->_name;
}

const int	&Form::getSignGrade( void ) const {
	return this->_grade_sign;
}

const int	&Form::getExecGrade( void ) const {
	return this->_grade_exec;
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
	return (str << form.getName() << ", form signing grade " << form.getSignGrade() << ", executing grade " << form.getExecGrade());
}