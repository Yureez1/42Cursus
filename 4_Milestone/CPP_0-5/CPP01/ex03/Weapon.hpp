/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:14:41 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:43:12 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

private:
    std::string _type;

public:
    Weapon();
    Weapon(const std::string &type);
    ~Weapon();

    const std::string &getType(void) const;
    void setType(const std::string &newType);
};

#endif