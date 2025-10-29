/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:30:05 by julien            #+#    #+#             */
/*   Updated: 2025/10/16 08:40:42 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"
#include "Base.hpp"

Base* generate(void) {
    int r = std::rand() % 3;

    switch(r) {
        case 0: std::cout << "[generate] -> A" << std::endl;
        return new A();

        case 1: std::cout << "[generate] -> B" << std::endl;
        return new B();
        
        default: std::cout << "[generate] -> C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (!p) {
        std::cout << "identify(Base*): nullptr" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown" << std::endl;
}
