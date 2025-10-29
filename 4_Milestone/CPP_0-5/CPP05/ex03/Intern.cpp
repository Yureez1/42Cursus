/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:41:18 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:07 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Defaut Constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const {

    static const std::string formList[] = {
        "shrubbery request",
        "robotomy request",
        "presidential request",
    };

    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (form == formList[i]) {
            index = i;
            break;
        }
    }

    switch(index) {
        case 0:
        std::cout << "Intern creates " << form << std::endl;
        return new ShrubberyCreationForm(target);

        case 1:
        std::cout << "Intern creates " << form << std::endl;
        return new RobotomyRequestForm(target);

        case 2:
        std::cout << "Intern creates " << form << std::endl;
        return new PresidentialPardonForm(target);

        default:
        std::cout << "Intern doesn't know this form" << std::endl;
        throw UnknownFormException();
    }
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Intern: unknown form name";
}



