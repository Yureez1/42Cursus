/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:46 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/19 14:10:20 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <cctype>

class RPN {

private:

    std::deque<int> _stack;

    bool isOperator(char token) const;
    int performOperation(const int nb1, const int nb2, const char op) const;

public:

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void evaluate(const std::string& expression);
};

#endif
