/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:52:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/26 17:43:30 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
    public: 
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( RobotomyRequestForm const &s );
        RobotomyRequestForm &operator=( RobotomyRequestForm const &s );
        ~RobotomyRequestForm( void );
        void    execute( Bureaucrat const &executor ) const;
};

#endif