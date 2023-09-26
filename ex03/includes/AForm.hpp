/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 17:47:57 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
			std::string	const	_name;
			bool				_is_signed;
			int const 			_grade_sign;
			int const 			_grade_exec;
	public:
			/* Constructors & Destructors */
			AForm( void );
			AForm( std::string name, int grade_sign, int grade_exec );
			virtual ~AForm( void );
			AForm( const AForm & );
			AForm& operator=( const AForm &);
			/* Getters */
			const std::string	&getName( void ) const;
			const int	&getSignGrade( void ) const ;
			const int	&getExecGrade( void ) const ;
			const bool	&getSigned( void ) const ;
			/* Methods */
			void	beSigned( Bureaucrat &bureaucrat);
			// void execute(Bureaucrat const & executor ) const;
			virtual void execute(Bureaucrat const & executor ) const = 0;
			/* Exceptions */
			class GradeTooHighException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
			class GradeTooLowException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
			class NotSignedException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
			class AlreadySignedException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif