/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:14:34 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:43:46 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name){}

HumanB::~HumanB() {}

void HumanB::setName(const std::string& name) {
    
    this->_name = name;
}

void HumanB::setWeapon(Weapon& weapon) {

    this->_weapon = &weapon;
}

void HumanB::attack() const {
    
    if (_weapon)
        std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}

