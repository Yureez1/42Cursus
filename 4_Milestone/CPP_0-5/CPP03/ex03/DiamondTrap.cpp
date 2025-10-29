/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:18:24 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/12 17:34:54 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_name"), _name("noname") {
    this->_hit_points    = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    
    std::cout << "DiamondTrap " << this->_name << " default CREATED" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    
    this->_hit_points    = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
    
    std::cout << "DiamondTrap " << this->_name << " ctor CREATED" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    
    if (this != &other) {
    
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name       = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
    
    std::cout << "DiamondTrap copy construted from " << this->_name << std::endl;
}


DiamondTrap::~DiamondTrap() {
    
    std::cout << "DiamondTrap " << this->_name << " DESTROYED" << std::endl;
}

void DiamondTrap::whoAmI() {
    
    if (this->_hit_points > 0) {
        std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name <<  std::endl;
    } else {
        std::cout << ClapTrap::_name << " can't launch whoAmI: is dead!" << std::endl;
    }
}
