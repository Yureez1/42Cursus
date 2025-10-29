/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:42:38 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/20 16:53:19 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal") {
    std::cout << this->_type << " Animal Constructor called" << std::endl;   
}

Animal::Animal(const std::string& type) {
    std::cout << "Animal Ctor Constructor called" << std::endl;
    this->_type = type;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << this->_type << " Animal Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << this->_type << " Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const { 
    std::cout << this->_type << ": " << "Unknown sound" << std::endl;
}