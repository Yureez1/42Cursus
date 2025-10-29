/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:28 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void) {

    std::cout << "===== INTERN CREATION =====" << std::endl;

    Intern RandomIntern;
    AForm* form;

    try {

        std::cout << "===== BUREAUCRATS CREATION =====" << std::endl;
        std::cout << std::endl;

        Bureaucrat high("HighRank", 1);
        std::cout << std::endl;

        std::cout << "===== INTERN SHRUBBERY FORM CREATION =====" << std::endl;
        std::cout << std::endl;

        form = RandomIntern.makeForm("shrubbery request", "Garden");
        std::cout << std::endl;

        std::cout << *form << std::endl;
        std::cout << std::endl;

        high.signForm(*form);
        std::cout << *form << std::endl;
        std::cout << std::endl;

        delete form;

        std::cout << "===== INTERN ROBOTOMY FORM CREATION =====" << std::endl;
        std::cout << std::endl;

        form = RandomIntern.makeForm("robotomy request", "Garden");
        std::cout << std::endl;

        std::cout << *form << std::endl;
        std::cout << std::endl;

        high.signForm(*form);
        std::cout << *form << std::endl;
        std::cout << std::endl;

        delete form;

        std::cout << "===== INTERN PRESIDENTIAL FORM CREATION =====" << std::endl;
        std::cout << std::endl;

        form = RandomIntern.makeForm("presidential request", "Garden");
        std::cout << std::endl;

        std::cout << *form << std::endl;
        std::cout << std::endl;

        high.signForm(*form);
        std::cout << *form << std::endl;
        std::cout << std::endl;

        delete form;

        std::cout << "===== INTERN UNKNOWN FORM CREATION =====" << std::endl;
        std::cout << std::endl;

        form = RandomIntern.makeForm("Unknown request", "Garden");
        std::cout << std::endl;

        std::cout << *form << std::endl;
        std::cout << std::endl;

        high.signForm(*form);
        std::cout << *form << std::endl;
        std::cout << std::endl;

        delete form;

        std::cout << "===== DESTRUCTOR TESTS =====" << std::endl;
        std::cout << std::endl;


    } catch (std::exception const& e) {
        std::cout << "Error detected: " << e.what() << std::endl;
    }

    return 0;
}
