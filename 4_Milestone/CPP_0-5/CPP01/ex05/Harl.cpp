/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:27:26 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:42:33 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
    
    std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
                 "special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    
    std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" <<std::endl;
}

void Harl::warning(void){
    
    std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I've been coming for "
                 "years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
    
    std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    
    typedef void (Harl::*Handler)(void);

    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Handler handlers[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*handlers[i])();
            return ;
        }
    }
    
    std::cout << "[ Unknown level ]" << std::endl;
}