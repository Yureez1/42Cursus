/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:43:20 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/20 16:52:58 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << this->_type << " Default Constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {
    std::cout << this->_type << " Ctor Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other._type) {
    std::cout << this->_type << " Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Dog::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << this->_type << " Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->_type << ": "<< "Waouf" << std::endl;
}

