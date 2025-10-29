/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:55:29 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 17:02:46 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string& const type) {
    std::cout << "AMateria ctor constructor called" << std::endl;   
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria AMateria::operator=(const AMateria& other) {

}


AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string AMateria::getType() const {
    return _type;
}