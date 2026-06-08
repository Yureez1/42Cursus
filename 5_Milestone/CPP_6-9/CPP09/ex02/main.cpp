/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:49 by jbanchon          #+#    #+#             */
/*   Updated: 2025/11/26 16:24:21 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    PmergeMe solver;

    try {
        solver.run(argc, argv);
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
