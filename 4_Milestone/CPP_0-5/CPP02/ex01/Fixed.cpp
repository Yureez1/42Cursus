/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:09 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/03 16:23:15 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    
    std::cout << "Default constructor called" << std::endl;
    
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
    
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;           
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;    
}

float Fixed::toFloat(void) const {
    
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
  
    return this->_value >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    
    os << obj.toFloat();
    return os;
}

Fixed::Fixed(const int n) {
    
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {

    std::cout << "Float constructor called" << std::endl;
    _value = (int)roundf(f * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const {
    
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    
    this->_value = raw;
}
