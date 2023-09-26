/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:56:07 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/11 13:21:04 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
    public: 
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( PresidentialPardonForm const &s );
        PresidentialPardonForm &operator=( PresidentialPardonForm const &s );
        ~PresidentialPardonForm( void );
        
        void executeForm(Bureaucrat const & executor ) const;
};

#endif