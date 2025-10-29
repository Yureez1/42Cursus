/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:04:54 by jbanchon          #+#    #+#             */
/*   Updated: 2025/08/25 16:47:27 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv) {

    if (argc != 4) {
        std::cout << "Usage : <filename> <string 1> <string 2>" << std::endl;
        return 1;
    }
    
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (filename.empty()) {
        std::cerr << "Error: Filename is empty" << std::endl;
        return 1;
    }

    if (s1.empty()) {
        std::cerr << "Error: s1 is empty" << std::endl;
        return 1;
    }

    Replacer r(filename, s1, s2);

    if (!r.readInput()) {
        std::cerr << "Error: cannot open input file " << filename << std::endl;
        return 2;
    }

    r.transform();

    if (!r.writeOuput()) {
        std::cerr << "Error: cannot write output file " << filename << std::endl;
        return 3;
    }
    return 0;
}