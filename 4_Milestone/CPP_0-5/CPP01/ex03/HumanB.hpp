/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:14:32 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/20 12:29:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    
private:
    std::string _name;
    Weapon* _weapon;

public:
    HumanB(const std::string& name);
    ~HumanB();
    
    void setName(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};


#endif