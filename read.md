/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/05/23 15:27:51 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef {{*CLASSNAMEUPPER*}}_HPP
#define {{*CLASSNAMEUPPER*}}_HPP

#include <iostream>

class {{*CLASSNAME*}} {
    private:
        
    public:
        {{*CLASSNAME*}}( void );
        ~{{*CLASSNAME*}}( void );
        {{*CLASSNAME*}}( const {{*CLASSNAME*}} & );
        {{*CLASSNAME*}}& operator=( const {{*CLASSNAME*}} &);
};

#endif



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/05/23 15:27:51 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/{{*HEADERFILENAME*}}"

{{*CLASSNAME*}}::{{*CLASSNAME*}}( void ) {
	std::cout << "[ {{*CLASSNAMEUPPER*}} ] Constructor called" << std::endl;
	return ;
}

{{*CLASSNAME*}}::~{{*CLASSNAME*}}( void ) {
	std::cout << "[ {{*CLASSNAMEUPPER*}} ] Destructor called" << std::endl;
	return ;
}

{{*CLASSNAME*}}::{{*CLASSNAME*}}( const {{*CLASSNAME*}} &copy ) {
	std::cout << "[ {{*CLASSNAMEUPPER*}} ] Copied" << std::endl;
	*this = copy;
	return ;
}

{{*CLASSNAME*}}& {{*CLASSNAME*}}::operator=( const {{*CLASSNAME*}} &copy ) {
	std::cout << "[ {{*CLASSNAMEUPPER*}} ]  Assignement operator called" << std::endl;
	return *this;
}

