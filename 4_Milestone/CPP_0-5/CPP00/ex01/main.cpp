/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:55:25 by jbanchon          #+#    #+#             */
/*   Updated: 2025/07/26 16:51:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(){

    Phonebook PhoneBook;

    PhoneBook.printTable();
    std::string command;
    while (true)
    {
        std::cout << "Enter a command [ADD], [SEARCH], [EXIT]: ";
        if (!std::getline(std::cin, command))
            break;
            
        if (command == "ADD" || command == "add")
            PhoneBook.addContact();
        else if (command == "SEARCH" || command == "search")
            PhoneBook.searchContacts();
        else if (command == "EXIT" || command == "exit")
            break ;
        else
            std::cout << "Invalid command." << std::endl;
    }
    
    return 0;
}
