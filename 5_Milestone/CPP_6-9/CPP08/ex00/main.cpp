/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:55:22 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/23 13:35:48 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void) {
    try {

        std::cout << "=====TEST easyfind in vector container=====" << std::endl;
        std::cout << std::endl;

        std::vector<int> vec;

        for (int i = 0; i < 100; i += 10) {
            vec.push_back(i);
        }

        int values[] = {0, 5, 10, 15, 42, 50, 77, 90};
        const int size = sizeof(values) / sizeof(values[0]);

        for (int i = 0; i < size; i++) {
            try {
                std::vector<int>::iterator it = easyfind(vec, values[i]);
                std::cout << "Found: " << *it << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Value: " << values[i] << " -> " << e.what() << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << "=====TEST easyfind in list container=====" << std::endl;
        std::cout << std::endl;

        std::list<int> lst;
        for (int i = 0; i < 100; i+=15) {
            lst.push_back(i);
        }
        int lst_values[] = {0, 15, 25, 42, 50, 100};
        const int lst_size = sizeof(lst_values) / sizeof(lst_values[0]);

        for (int i = 0; i < lst_size; i++) {
            try {
                std::list<int>::iterator it = easyfind(lst, lst_values[i]);
                std::cout << "Found: " << *it << std::endl;
            } catch (const std::exception& e) {
                std::cout << "lst_vvalue: " << lst_values[i] << " ->" << e.what() << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cout << "Exception caugth: " << e.what() << std::endl;
    }
    return 0;
}
