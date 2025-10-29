/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:22:29 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:44:16 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unamed") {}

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
    
    std::cout << this->_name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
    
    std::cout << this -> _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
    
    this->_name = name;
}
