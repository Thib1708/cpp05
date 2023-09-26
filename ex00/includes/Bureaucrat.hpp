/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/11 12:54:58 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
            std::string	const _name;
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