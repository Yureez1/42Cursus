/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:18:38 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/12 17:33:59 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

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
    }
    std::cout << std::endl;
    {
        std::cout << "\n===== " << "SCAVTRAP - BASIC TESTS" << " =====\n";
        ScavTrap b("T-999");
        
        // Attack with EP & HP OK
        b.attack("Dummy");
        
        // Partial damage
        b.takeDamage(5);
        
        // Partial healing (BASE: 100)
        b.beRepaired(5); // HP: 95

        // Special competence
        b.guardGate();

        std::cout << "\n===== " << "SCAVTRAP - DRAIN ENERGY TO 0 - TESTS" << " =====\n";
        for (int i = 0; i < 47; i++) {
            b.attack("Dummy");
        }
        std::cout << "\n===== " << "SCAVTRAP - NO EP - TESTS" << " =====\n";
        // Attack without EP
        b.attack("Dummy");
        
        // Heal without EP
        b.beRepaired(1);
        
        // Kill SCAVTRAP
        std::cout << "\n===== " << "SCAVTRAP - DEATH - TESTS" << " =====\n";
        b.takeDamage(100);
        b.attack("Dummy");
        b.beRepaired(5);
        b.takeDamage(1);
        b.guardGate();
    }
    std::cout << std::endl;
    {
        std::cout << "\n===== " << "FRAGTRAP - BASIC TESTS" << " =====\n";
        FragTrap c("T-9999");

        // Attack with EP & HP OK
        c.attack("Dummy");
        
        // Partial damage
        c.takeDamage(5);
        
        // Partial healing (BASE: 100)
        c.beRepaired(5); // HP: 95

        // Special competence
        c.highFivesGuys();
        
        std::cout << "\n===== " << "FRAGTRAP - DRAIN ENERGY TO 0 - TESTS" << " =====\n";
        for (int i = 0; i < 98; i++) {
            c.attack("Dummy");
        }
        std::cout << "\n===== " << "FRAGTRAP - NO EP - TESTS" << " =====\n";
        // Attack without EP
        c.attack("Dummy");
        
        // Heal without EP
        c.beRepaired(1);
        
        // Kill FRAGTRAP
        std::cout << "\n===== " << "FRAGTRAP - DEATH - TESTS" << " =====\n";
        c.takeDamage(100);
        c.attack("Dummy");
        c.beRepaired(5);
        c.takeDamage(1);
        c.highFivesGuys();
    }
    std::cout << std::endl;
    {
        std::cout << "\n===== " << "DIAMONDTRAP - BASIC TESTS" << " =====\n";
        DiamondTrap d;
        
        // Attack with EP & HP OK
        d.attack("Dummy");
        
        // Partial damage
        d.takeDamage(5);
        
        // Partial healing (BASE: 100)
        d.beRepaired(5); // HP: 95

        // Special competence
        d.guardGate();
        d.highFivesGuys();
        d.whoAmI();
        
        std::cout << "\n===== " << "DIAMONDTRAP - DRAIN ENERGY TO 0 - TESTS" << " =====\n";
        for (int i = 0; i < 48; i++) {
            d.attack("Dummy");
        }
        std::cout << "\n===== " << "DIAMONDTRAP - NO EP - TESTS" << " =====\n";
        // Attack without EP
        d.attack("Dummy");
        
        // Heal without EP
        d.beRepaired(1);
        
        // Kill DIAMONDTRAP
        std::cout << "\n===== " << "DIAMONDTRAP - DEATH - TESTS" << " =====\n";
        d.takeDamage(100);
        d.attack("Dummy");
        d.beRepaired(5);
        d.takeDamage(1);
        d.guardGate();
        d.highFivesGuys();
        d.whoAmI();
    }
    
	return 0;
}