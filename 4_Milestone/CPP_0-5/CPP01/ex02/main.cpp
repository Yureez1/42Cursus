/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:04:49 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/27 11:43:57 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main() {
    
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // Print Memory addresses
    std::cout << "Address of str         :" << &str << std::endl;
    std::cout << "Address held by PTR.   :" << stringPTR << std::endl;
    std::cout << "Address held by REF.   :" << &stringREF << std::endl;

    std::cout << std::endl;

    // Print values
    std::cout << "Value of str.          :" << str << std::endl;
    std::cout << "Value pointed by PTR   :" << *stringPTR << std::endl;
    std::cout << "Value pointed by REF   :" << &stringREF << std::endl;

    return 0;
}