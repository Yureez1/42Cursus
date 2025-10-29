/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:40:56 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/09 15:41:44 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _value(other._value) {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Conversion to Fixed to Float
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

// Int constructor
Fixed::Fixed(const int n) {
    
    _value = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float f) {
    
    _value = (int)roundf(f * (1 << _fractionalBits));
}

// getRawBits function
int Fixed::getRawBits(void) const {
    
    return this->_value;
}

// setRawBits function
void Fixed::setRawBits(int const raw) {
    
    this->_value = raw;
}

bool Fixed::operator>(const Fixed& rhs) const {
    
    return this->_value > rhs._value;
}

// Comparison operators
bool Fixed::operator<(const Fixed& rhs) const { return this->_value < rhs._value; }

bool Fixed::operator>=(const Fixed& rhs) const { return this->_value >= rhs._value; }

bool Fixed::operator<=(const Fixed& rhs) const { return this->_value <= rhs._value; }

bool Fixed::operator==(const Fixed& rhs) const { return this->_value == rhs._value; }

bool Fixed::operator!=(const Fixed& rhs) const { return this->_value != rhs._value; }

// arithmetic operators 
Fixed Fixed::operator+(const Fixed& rhs) const {
    
    Fixed result;
    result.setRawBits(this->_value + rhs._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    
    Fixed result;
    result.setRawBits(this->_value - rhs._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    
    Fixed result;
    long tmp = static_cast<long>(this->_value) * static_cast<long>(rhs._value);
    result.setRawBits(static_cast<int>(tmp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    
    Fixed r;
    long num = static_cast<long>(this->_value) << _fractionalBits;
    long den = static_cast<long>(rhs._value);

    long half;
    if (den >= 0)
        half = den / 2;
    else
        half = -den / 2;
    long q;
    if (num >= 0)
        q = (num + half) / den;
    else
        q = (num - half) / den;

    r.setRawBits(static_cast<int>(q));
    return r;
}

// Pre-increment
Fixed& Fixed::operator++() {
    
    ++this->_value;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    
    Fixed old(*this);
    ++(*this);
    return old;   
}

// Pre-decrement
Fixed& Fixed::operator--() {
    
    --this->_value;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    
    Fixed old(*this);
    --(*this);
    return old;    
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    
    if (a._value <= b._value)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    
        if (a._value <= b._value)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {

    if (a._value >= b._value)
        return a;
    else
        return b;
}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    
        if (a._value >= b._value)
        return a;
    else
        return b;
}
