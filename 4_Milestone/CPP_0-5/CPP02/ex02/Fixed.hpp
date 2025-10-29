/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:41:00 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/05 15:25:09 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    
    Fixed(const int n);
    Fixed(const float f);

    float   toFloat(void) const;
    int     toInt(void) const;

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    // Comparisons operators
    bool    operator>(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator==(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    // Pre-incrementation | Pre-decrementation operators
    Fixed&  operator++();
    Fixed&  operator--();

    // Post-incrementation | Pre-decrementation operators
    Fixed   operator++(int);
    Fixed   operator--(int);

    static  Fixed&          min(Fixed& a, Fixed& b);
    static  Fixed&          max(Fixed& a, Fixed& b);

    static const Fixed&     min(const Fixed& a, const Fixed& b);
    static const Fixed&     max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif