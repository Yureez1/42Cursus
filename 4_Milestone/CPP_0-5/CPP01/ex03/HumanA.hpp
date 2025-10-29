/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:14:35 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/20 12:29:07 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    
private:
    std::string _name;
    Weapon& _weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
    
    void setName(const std::string& name);
    void attack() const;
};


#endif