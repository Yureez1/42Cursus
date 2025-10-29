/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:59:57 by jbanchon          #+#    #+#             */
/*   Updated: 2025/07/26 16:52:13 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {

    // std::cout << "Constructor Contact Called" << std::endl;
    return ;
    
}    

bool is_digit(const std::string &str) {
    
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++) {
        
        char c = str[i];
        if (c < '0' || c > '9')
            return false;
            
    }
    return true;
}

bool isValidPhoneNumber(const std::string &str) {

    if (str.size() != 10 || !is_digit(str)) {
        std::cout << "Phone Number must have exactly 10 digits." << std::endl;
        return false; 
    }
    return true;
}

bool isValidName(const std::string &str) {
    
    if (!(str[0] >= 'A' && str[0] <= 'Z')) {
        std::cout << "It must start with an uppercase letter." << std::endl;
        return false;
    }

    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            std::cout << "Only the first letter must be uppercase. The rest must be lowercase." << std::endl;
            return false;
        }
    }
    
    return true;
}

std::string Contact::getFirstName() const {
    return this->FirstName;
}

std::string Contact::getLastName() const {
    return this->LastName;    
}

std::string Contact::getNickname() const {
    return this->NickName;
}

std::string Contact::getPhoneNumber() const {
    return this->PhoneNumber;
}

std::string Contact:: getDarkestSecret() const {
    return this->DarkestSecret;
}

std::string prompt(const std::string &field) {
    
    std::string input;
    
    while (true)
    {
        std::cout << field << ": ";
        if(!std::getline(std::cin, input)){
            std::cout << "\nEOF detected. Aborting input." << std::endl;
            return "";
        }
        
        if (!input.empty())
            return input;
        std::cout << "This field cannot be empty" << std::endl;
    }
    
    return input;    
}

void Contact::setInfo() {

    FirstName = prompt("First Name");
    if (FirstName.empty())
        return;
    while (!isValidName(FirstName)) {
        FirstName = prompt("First Name");
        if (FirstName.empty())
            return;
    }

    LastName = prompt("Last Name");
    if (LastName.empty())
        return;
    while (!isValidName(LastName)) {
        LastName = prompt("Last Name");
        if (LastName.empty())
            return;
    }
    
    NickName = prompt("Nickname");
    if (NickName.empty())
        return;
    
    PhoneNumber = prompt("Phone Number");
    if (PhoneNumber.empty())
        return ;
    while (!isValidPhoneNumber(PhoneNumber)) {
        PhoneNumber = prompt("Phone Number");
        if (PhoneNumber.empty())
            return;
    }

    DarkestSecret = prompt("Darkest Secret");
    if (DarkestSecret.empty())
        return;
}

void Contact::displayFullContact() const {

    std::cout << "First Name : " << FirstName << std::endl;
    std::cout << "Last Name : " << LastName << std::endl;
    std::cout << "Nickname : " << NickName << std::endl;
    std::cout << "Phone Number : " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret : " << DarkestSecret << std::endl;
    return ;
}

Contact::~Contact( void ) {
    
    // std::cout << "Destructor Contact Called" << std::endl;
    return ;
    
}