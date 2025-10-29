/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:45 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:41:35 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int levelIndex(const std::string& s) {

    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (s == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    const std::string arg = argv[1];
    int idx = levelIndex(arg);

    if (idx == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }

    switch(idx) {
        
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
            
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;

        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
            
        default:
            break;
        }
    return 0;
}