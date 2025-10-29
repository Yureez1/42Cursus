/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:15:56 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/16 12:55:15 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>

void print(const T &x) {
    std::cout << x << " " << std::endl;
}

template<typename T>
void inc(T &x) {
    x++;
}

void toUpper(std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' || str[i] <= 'z')
           str[i] -= 32;
    }
}

int main(void) {
    {
        std::cout << "===== INT (non const) =====" << std::endl;
        std::cout << std::endl;

        int a[] = {0, 1, 2, 3, 4, 5};
        size_t n = sizeof(a) / sizeof(a[0]);

        std::cout << "before : " << std::endl;
        ::iter(a, n, print<int>);
        std::cout << std::endl;

        ::iter(a, n, inc<int>);
        std::cout << "after : " << std::endl;

        ::iter(a, n, print<int>);
        std::cout << std::endl;
    }
    {
        std::cout << "===== CHAR (non const) =====" << std::endl;
        std::cout << std::endl;

        std::string s[] = {"hello", "iter", "template"};
        size_t n = sizeof(s) / sizeof(s[0]);

        std::cout << "before  : " << std::endl;
        ::iter(s, n, print<std::string>);
        std::cout << std::endl;

        ::iter(s, n, toUpper);
        std::cout << "after : " << std::endl;
        ::iter(s, n, print<std::string>);
        std::cout << std::endl;
    }
    {
        std::cout << "===== double (const array) =====" << std::endl;
        const double d[] = {1.5, 2.25, 3.75};
        size_t n = sizeof(d) / sizeof(d[0]);

        ::iter(d, n, print<double>);
        std::cout << std::endl;

    }
}
