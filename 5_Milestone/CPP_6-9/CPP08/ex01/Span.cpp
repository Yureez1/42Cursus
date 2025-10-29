/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:56:59 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/23 17:55:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _capacity(n), _data() {}

Span::Span(const Span& other) : _capacity(other._capacity), _data(other._data){}

Span Span::operator=(const Span& other) {
    if (this != &other){
        _capacity = other._capacity;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

unsigned int Span::size() const {
    return static_cast<unsigned int>(_data.size());
}

unsigned int Span::capacity() const {
    return _capacity;
}

void Span::addNumber(int n) {
    if (_data.size() >= _capacity)
        throw std::overflow_error("Span is full");
    _data.push_back(n);
}

template <typename It>
void Span::addMultipleNumber(It first, It last) {
    if (_data.size() >= _capacity)
        throw std::overflow_error("Span is full");
    unsigned int needed = 0;
    for (It it = first; it != last; it++)
        needed++;
    if (_data.size() + needed >= _capacity)
        throw std::overflow_error("Span is full");
    for (It it = first; it != last; it++)
        _data.push_back(*it);
}

unsigned int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    unsigned int best = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::size_type i = 1; i < sorted.size(); i++) {
        long diff = static_cast<long>(sorted[i] - static_cast<long>(sorted[i - 1]));
        if (diff < 0)
            diff = -diff;
        if (static_cast<unsigned long>(diff) < best)
            best = static_cast<unsigned int>(diff);
        if (best == 0)
            break;
    }
    return best;
}

unsigned int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");

    std::vector<int>::const_iterator itMin = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator itMax = std::max_element(_data.begin(), _data.end());

    long diff = static_cast<long>(*itMax) - static_cast<long>(*itMin);
    if (diff < 0)
        diff = -diff;
    return static_cast<unsigned int>(diff);
}





