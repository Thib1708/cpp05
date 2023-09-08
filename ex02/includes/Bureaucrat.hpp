/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/06 16:42:16 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
            std::string	_name;
            int			_grade;
    public:
			/* Constructors & Destructors */
            Bureaucrat( void );
            Bureaucrat( std::string name, int grade );
            ~Bureaucrat( void );
            Bureaucrat( const Bureaucrat & );
            Bureaucrat& operator=( const Bureaucrat &);
			/* Setters & Getters */
			const std::string	&getName( void ) const ;
			const int 			&getGrade( void ) const ;
			/* Methods */
			void	upgrade( void );
			void	downgrade( void );
			void	signedForm( Form &form);
			/* Class */
			class GradeTooHighException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
			class GradeTooLowException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
			};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);
#endif