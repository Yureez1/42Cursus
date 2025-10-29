/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:22:25 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/28 14:07:43 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    
    int N = 5;
    
    Zombie* horde = zombieHorde(N, "Foo");
    if (!horde) {
        std::cout << "Allocation failed" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    
    // if (!zombieHorde(0, "Nope")) {
    //     std::cout << "OK: N <= 0 returns NULL" << std::endl;
    // }

    return 0;
}