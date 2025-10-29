/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:15:24 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/17 09:00:01 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _array(0), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(0), _size(n) {
    _array = new T[_size]();
}

template<typename T>
Array<T>::Array(const Array& other) : _array(0), _size(other._size) {
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* newArray = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
            newArray[i] = other._array[i];

        delete[] _array;
        _array = newArray;
        _size = other._size;
        }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] _array;
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Array: index out of range");
    }
    return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Array: index out of range");
    }
    return _array[index];
}
