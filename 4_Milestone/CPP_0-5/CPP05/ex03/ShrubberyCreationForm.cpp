/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:20 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/06 10:16:02 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
   std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::doExecute() const {
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream out(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!out)
        throw FileOpenException();
    out <<
        "       -_     \n"
        "  /~~     ~~ \\  \n"
        " /~~        ~~\\\n"
        "{             }\n"
        " \\  _-   -_  //\n"
        "   ~  \\ //  ~ \n"
        "_- -   | | _-_\n"
        "  _ -  | |   -_\n"
        "      // \\    \n";
}
