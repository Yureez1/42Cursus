/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:44 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/19 15:13:35 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}


RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack= other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::performOperation(const int nb1, const int nb2, const char op) const {
    switch (op) {
        case '+':
            return nb1 + nb2;
        case '-':
            return nb1 - nb2;
        case '/':
            return nb1 / nb2;
        case '*':
            return nb1 * nb2;
        default:
            std::cerr << "Error: Undefined behavior for this operand" << std::endl;
            return 0;
    }
}

bool RPN::isOperator(char token) const {
    return (token == '+' || token == '-' || token == '/' || token == '*');
}


void RPN::evaluate(const std::string& expression) {
    _stack.clear();

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
            int nb = std::atoi(token.c_str());
            _stack.push_back(nb);
        }
        else if (token.length() == 1 && isOperator(token[0]) ) {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return ;
            }
            int nb2 = _stack.back();
            _stack.pop_back();
            int nb1 = _stack.back();
            _stack.pop_back();
            if (token[0] == '/' && nb2 == 0) {
                std::cerr << "Error: divison by 0" << std::endl;
                return;
            }
            int result = performOperation(nb1, nb2, token[0]);
            _stack.push_back(result);
        }
        else {
            std::cerr << "Error: token is invalid" << std::endl;
            return;
        }
    }
    if (_stack.size() == 1) {
        std::cout << "Result: " << _stack.back() << std::endl;
    } else {
        std::cerr << "Error: malformed expression" << std::endl;
    }
}
