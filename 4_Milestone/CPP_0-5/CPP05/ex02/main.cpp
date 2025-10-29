/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:27:28 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/07 15:21:45 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main(void) {
    srand(time(NULL));

    try {
        std::cout << "===== BUREAUCRATS CREATION =====" << std::endl;
        std::cout << std::endl;

        Bureaucrat high("HighRank", 1);
        std::cout << std::endl;

        Bureaucrat mid("MidRank", 50);
        std::cout << std::endl;

        Bureaucrat low("LowRank", 150);
        std::cout << std::endl;

        std::cout << "===== FORMS CREATION =====" << std::endl;
        std::cout << std::endl;

        ShrubberyCreationForm shrub("home");
        std::cout << std::endl;

        RobotomyRequestForm robot("E.T");
        std::cout << std::endl;

        PresidentialPardonForm pardon("populas");
        std::cout << std::endl;

        std::cout << "===== SIGNING TESTS =====" << std::endl;
        std::cout << std::endl;

        low.signForm(shrub);
        std::cout << std::endl;

        mid.signForm(shrub);
        std::cout << std::endl;

        high.signForm(robot);
        std::cout << std::endl;

        high.signForm(pardon);
        std::cout << std::endl;

        std::cout << "===== EXECUTION TESTS =====" << std::endl;
        std::cout << std::endl;

        low.executeForm(shrub);
        std::cout << std::endl;

        mid.executeForm(shrub);
        std::cout << std::endl;

        low.executeForm(robot);
        std::cout << std::endl;

        high.executeForm(robot);
        std::cout << std::endl;

        high.executeForm(pardon);
        std::cout << std::endl;

        std::cout << "===== ALREADY SIGNED TEST =====" << std::endl;
        std::cout << std::endl;

        mid.signForm(shrub);
        std::cout << std::endl;

        std::cout << "===== DESTRUCTOR TESTS =====" << std::endl;
        std::cout << std::endl;

    } catch (std::exception const& e) {
        std::cout << "Error detected: " << e.what() << std::endl;
    }

    return 0;
}
