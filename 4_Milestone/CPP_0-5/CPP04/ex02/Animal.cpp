/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:38:11 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 12:58:35 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : _type("UAnknown AAnimal"){
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) {
    std::cout << "AAnimal ctor constructor called" << std::endl;
    this->_type = type;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return this->_type;
}

void AAnimal::makeSound() const {
    std::cout << this->_type << ": " << "Unknown sound" << std::endl;
}