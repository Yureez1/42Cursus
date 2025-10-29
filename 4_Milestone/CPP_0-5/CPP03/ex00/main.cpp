/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:25:16 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/15 12:46:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    {
        std::cout << "\n===== " << "CLAPTRAP - BASIC TESTS" << " =====\n";
        ClapTrap a("T-800");
        
        // Attack with EP & HP OK
        a.attack("Dummy");
        
        // Partial damage
        a.takeDamage(5);
        
        // Partial healing (BASE: 10)
        a.beRepaired(5); // HP: 8

        std::cout << "\n===== " << "CLAPTRAP - DRAIN ENERGY TO 0 - TESTS" << " =====\n";
        for (int i = 0; i < 8; i++) {
            a.attack("Dummy");
        }
        std::cout << "\n===== " << "CLAPTRAP - NO EP - TESTS" << " =====\n";
        // Attack without EP
        a.attack("Dummy");
        
        // Heal without EP
        a.beRepaired(1);
        
        // Kill ClapTrap
        std::cout << "\n===== " << "CLAPTRAP - DEATH - TESTS" << " =====\n";
        a.takeDamage(10);
        a.attack("Dummy");
        a.beRepaired(5);
        a.takeDamage(1);

        ClapTrap b;
        b.attack("Default");

        ClapTrap c(b);
        c.attack("Copy");

        c = b;
        c.attack("Operator");
        
    }
}