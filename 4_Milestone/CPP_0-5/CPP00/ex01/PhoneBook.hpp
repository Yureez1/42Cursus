/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:55:32 by jbanchon          #+#    #+#             */
/*   Updated: 2025/07/26 16:51:18 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Phonebook {

private:

    Contact contacts[8];
    int     contactCount;
    int     oldestIndex;
    
public:

    Phonebook( void );
    ~Phonebook( void );
    
    void addContact();
    void searchContacts();
    void printTable();
    void printBottomLine();
    void displayContactAtIndex(int index) const;

};

#endif