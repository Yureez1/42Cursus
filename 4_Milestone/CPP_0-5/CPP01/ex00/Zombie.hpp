/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:09:17 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:44:27 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

private:
    std::string _name;

public:
    Zombie();
    Zombie(const std::string &name);
    ~Zombie();

    void announce(void) const;
    void setName(const std::string &name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif