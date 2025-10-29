/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:38:38 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/24 12:59:00 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    this->_brain = new Brain();
    std::cout << this->_type << " Default constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : AAnimal(type) {
    this->_brain = new Brain();
    std::cout << this->_type << " Ctor Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other._type) {
    this->_brain = new Brain(*other._brain);
    std::cout << this->_type << " Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << this->_type << " Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->_type << ": " << "Miaou" << std::endl;
}

Brain& Cat::getBrain() const {
    return *this->_brain;
}