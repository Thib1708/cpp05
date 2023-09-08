/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:03:37 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/08 09:51:29 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
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