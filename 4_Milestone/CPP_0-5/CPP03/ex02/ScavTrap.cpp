/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:23:43 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/12 15:02:43 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname") {
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;

    std::cout << this->_name << " CREATED as default ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << this->_name << " CREATED as ctor ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    
    std::cout << "ScavTrap created as copy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << this->_name << " DESTROYED as ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    
    if (this->_hit_points == 0) {
        std::cout << this->_name << " cannot attack: is dead!" << std::endl;
        return ;
    }
    
    if (this->_energy_points == 0) {
        std::cout << this->_name << " is too weak to attack." << std::endl;
        return ;
    }
    
    
    std::cout << "ScavTrap " << this->_name << " ferociously attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << this->_name << " now has " << this->_energy_points << " EP." << std::endl;
}

void ScavTrap::guardGate() {

    if (this->_hit_points == 0) {
        std::cout << this->_name << " can't launch GATE KEEPER: is dead!" << std::endl;
        return ;
    }
    
    if (this->_energy_points == 0) {
        std::cout << this->_name << " GATE KEEPER: not enough EP!" << std::endl;
        return ;
    }
    
    std::cout << this->_name << " GATE KEEPER MODE ACTIVATED" << std::endl;
}