/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:55:29 by jbanchon          #+#    #+#             */
/*   Updated: 2025/07/26 16:52:02 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook( void ) : contactCount(0), oldestIndex(0){

    // std::cout << "Phonebook Constructor Called" << std::endl;    
    return ;

}

std::string truncate(std::string str) {
    
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void Phonebook::addContact() {
    
    if (contactCount < 8) {
        contacts[contactCount].setInfo();
        contactCount++;
    } else {
        contacts[oldestIndex].setInfo();
        oldestIndex = (oldestIndex + 1) % 8;
    }
}


void Phonebook::printTable() {

    std::cout << '+'; 
    for (int i = 0; i < 6; i++){
        std::cout << std::string(10, '-') << '+';
    }
    std::cout << std::endl;
    
    std::cout << std::right 
              << '|' << std::setw(10) << "Index"
              << '|' << std::setw(10) << "FirstName" 
              << '|' << std::setw(10) << "LastName" 
              << '|' << std::setw(10) << "NickName" 
              << '|' << std::setw(10) << truncate("PhoneNumber") 
              << '|' << std::setw(10) << truncate("DarkestSecret") 
              << '|' << std::endl;
    
    std::cout << '+';
    for (int i = 0; i < 6; i++) {
        std::cout << std::string(10, '-') << '+';
    }
    std::cout << std::endl;
    return ;
}

void Phonebook::printBottomLine() {

    std::cout << '+';
    
    for (int i = 0; i < 6; i++) {
        std::cout << std::string(10, '-') << '+';
    }
    std::cout << std::endl;
}

void Phonebook::searchContacts() {

    if (contactCount == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    printTable();
    for (int i = 0; i < contactCount; i++) {
        
        int displayIndex = (oldestIndex + i) % 8;
        std::cout << "|" << std::setw(10) << i << "|" 
                  << std::setw(10) << truncate(contacts[displayIndex].getFirstName()) << "|" 
                  << std::setw(10) << truncate(contacts[displayIndex].getLastName()) << "|" 
                  << std::setw(10) << truncate(contacts[displayIndex].getNickname()) <<  "|"
                  << std::setw(10) << truncate(contacts[displayIndex].getPhoneNumber()) << "|"
                  << std::setw(10) << truncate(contacts[displayIndex].getDarkestSecret()) << "|" << std::endl;

    }
    printBottomLine();
    
    std::string input;
    std::cout << "Enter an index to display contact info: ";
    if (!std::getline(std::cin, input))
        return;
    if (input.empty() || std::cin.eof())
        return ;
    if (!is_digit(input)) {
        
        std::cout << "Invalid index." << std::endl;
        return;
        
    }
    int index = std::atoi(input.c_str());
    if (index >= 0 && index < contactCount) {
        contacts[index].displayFullContact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

Phonebook::~Phonebook( void ){
    
    // std::cout << "Phonebook Destructor Called" << std::endl;
    return;
    
}