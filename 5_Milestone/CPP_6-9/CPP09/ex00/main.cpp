/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:20 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/16 14:56:25 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string inputFile = argv[1];

    BitcoinExchange btc(DATABASE_FILE);

    btc.processInputFile(inputFile);
    return EXIT_SUCCESS;
}
