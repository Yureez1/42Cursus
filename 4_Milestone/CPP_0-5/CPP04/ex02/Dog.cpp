/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:39:31 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 12:59:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    this->_brain = new Brain();
    std::cout << this->_type << " Default Constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : AAnimal(type) {
    this->_brain = new Brain();
    std::cout << this->_type << " Ctor Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other._type) {
    this->_brain = new Brain(*other._brain);
    std::cout << this->_type << " Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << this->_type << " Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->_type << ": " << "Waouf" << std::endl;
}

Brain& Dog::getBrain() const {
    return *this->_brain;
}