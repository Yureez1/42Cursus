/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:18:19 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/12 15:06:52 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noname"), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << this->_name << " CREATING as default CREATURE!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << this->_name << " CREATING ctor CREATURE!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage) {
    std::cout << this->_name << " COPY CONSTRUCTED" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {

    if (this != &other) {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << this->_name << " AUTO-DESTRUCTION ABORT!" << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    
    if (this->_hit_points == 0) {
        std::cout << this->_name << " cannot attack: is dead!" << std::endl;
        return ;
    }

    if (this->_energy_points == 0) {
        std::cout << this->_name << " cannot attack: not enough EP!" << std::endl;
        return ;
    }
    
    std::cout << this->_name << " : attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << this->_name << " now has " << this->_energy_points << " EP." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (this->_hit_points == 0) {
        std::cout << this->_name << " is already dead!" << std::endl;
        return ;
    }
    
    std::cout << this->_name << " takes " << amount << " damage!" << std::endl;

    if (amount >= this->_hit_points)
        this->_hit_points = 0;
    else
        this->_hit_points -= amount;
    
    std::cout << this->_name << " now has " << this->_hit_points << " HP!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->_energy_points == 0) {
        std::cout << this->_name << " cannot repair: not enough EP!" << std::endl;
        return ;
    }
    
    if (this->_hit_points == 0) {
        std::cout << this->_name << " cannot repair: is dead!" << std::endl;
        return ;    
    }
    
    if (this->_hit_points == 10 || this->_hit_points == 100) {
        std::cout << this->_name << " cannot repair: already full HP" << std::endl;
        return ;
    }
        
    std::cout << this->_name << " repairs " << amount << " HP!" << std::endl;
    this->_hit_points += amount;
    this->_energy_points--;
    std::cout << this->_name << " now has " << this->_hit_points << " HP and " << this->_energy_points << " EP." << std::endl;
}
