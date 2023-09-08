/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/08 11:43:48 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

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
			void	signForm( Form &form);
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