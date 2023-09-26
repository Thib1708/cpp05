/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:03:37 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/11 13:20:54 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
    public: 
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm const &s );
        ShrubberyCreationForm &operator=( ShrubberyCreationForm const &s );
        ~ShrubberyCreationForm( void );
        void    executeForm( Bureaucrat const &executor ) const;

        class CantOpenFileException: public std::exception {
            public :
                    virtual const char	*what( void ) const throw();
        };
};

#endif