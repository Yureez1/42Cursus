/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 08:56:29 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/19 15:06:12 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal"){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& type) {
    std::cout << "Animal ctor constructor called" << std::endl;
    this->_type = type;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << this->_type << ": " << "Unknown sound" << std::endl;
}