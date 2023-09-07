/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/07 10:44:08 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
			std::string	_name;
			bool		_is_signed;
			int			_grade_sign;
			int			_grade_exec;
	public:
			/* Constructors & Destructors */
			Form( void );
			Form( std::string name, int grade_sign, int grade_exec );
			~Form( void );
			Form( const Form & );
			Form& operator=( const Form &);
			/* Getters */
			const std::string	&getName( void ) const ;
			const int	&getGrade( void ) const ;
			const bool	&getSigned( void ) const ;
			/* Methods */
			void	beSigned( Bureaucrat &bureaucrat);
			/* Exceptions */
			class GradeTooHighException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
			class GradeTooLowException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif