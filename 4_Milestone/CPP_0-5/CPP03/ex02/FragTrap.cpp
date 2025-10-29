/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:23:30 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/12 15:08:36 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noname") {
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    
    std::cout << this->_name << " CREATED as default FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {

    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    
    std::cout << this->_name << " CREATED as ctor FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    
    *this = other;
    std::cout << "FragTrap created as copy" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {

    if (this->_hit_points > 0) {
        std::cout << this->_name << " GOOD JOB, HIGH FIVES GUYS!" << std::endl; 
    } else {
        std::cout << this->_name << " can't launch high fives guys: is dead!" << std::endl;
    }
}


FragTrap::~FragTrap() {

    std::cout << this->_name << " DESTROYED as FragTrap" << std::endl;
}