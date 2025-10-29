/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:43:15 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/20 16:52:48 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << this->_type << " Default Constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
    std::cout << this->_type << " Ctor Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other._type) {
    std::cout << this->_type << " Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << this->_type << " Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->_type << ": " << "Miaou" << std::endl;
}
