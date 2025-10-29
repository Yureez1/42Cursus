/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:15:29 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/15 17:02:29 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <string>
#include <iostream>

template<typename T>

class Array {

    private:
    T* _array;
    unsigned int _size;

    public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    unsigned int size() const;

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif
