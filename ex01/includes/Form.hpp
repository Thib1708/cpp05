/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 17:00:35 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
			std::string	const _name;
			bool		_is_signed;
			int			const _grade_sign;
			int			const _grade_exec;
	public:
			/* Constructors & Destructors */
			Form( void );
			Form( std::string name, int grade_sign, int grade_exec );
			~Form( void );
			Form( const Form & );
			Form& operator=( const Form &);
			/* Getters */
			const std::string	&getName( void ) const;
			const int	&getSignGrade( void ) const ;
			const int	&getExecGrade( void ) const ;
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