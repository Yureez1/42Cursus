/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:32:55 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/25 10:48:43 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Replacer {

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _input;
    std::string _output;
    
public:
    Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
    
    bool readInput();
    void transform();
    bool writeOuput() const;
};

#endif