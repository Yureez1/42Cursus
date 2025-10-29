/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:15:27 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/17 09:01:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {

    std::cout << "===== TEST 1 : Default Constructor =====" << std::endl;
    std::cout << std::endl;

    Array<int> empty;
    std::cout << "Size : " << empty.size() << std::endl;
    try {
        empty[0] = 42;
    } catch (const std::exception& e) {
        std::cout << "Exception caught : " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== TEST 2: Constructor with size =====" << std::endl;
    std::cout << std::endl;

    Array<int> numbers(5);
    std::cout << "Size : " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    std::cout << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST 3: Out of bounds =====" << std::endl;
    std::cout << std::endl;

    try {
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught : " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== TEST 4: Copy Constructor =====" << std::endl;
    std::cout << std::endl;

    Array<int> copy(numbers);
    std::cout<< "Size of copy : " << copy.size() << std::endl;

    copy[0] = 999;
    std::cout << "copy[0] " << copy[0] << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST 5: Operator =  =====" << std::endl;
    std::cout << std::endl;

    Array<int> assigned;
    assigned = numbers;
    std::cout << "Size of assigned : " << assigned.size() << std::endl;
    assigned[1] = 777;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;
    std::cout << "numbers[1] = " << numbers[1] << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST 6: Basics  =====" << std::endl;
    std::cout << std::endl;

    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "World";
    words[2] = "777";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";

    std::cout << std::endl;
    std::cout << "===== TEST 5: Copy const Tab  =====" << std::endl;
    std::cout << std::endl;

    const Array<std::string> constWords(words);
    std::cout << "Size : " << constWords.size() << std::endl;
    std::cout << "constWords[1] = " << constWords[1] << std::endl;
    try {
        std::cout << constWords[5] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caugth : " << e.what() << std::endl;
    }
}

