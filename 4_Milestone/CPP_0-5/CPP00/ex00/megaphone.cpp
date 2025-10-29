/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:42:58 by jbanchon          #+#    #+#             */
/*   Updated: 2025/07/24 14:15:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv){
    
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    
    for (int i = 1; i < argc; i++) {

        int j = 0;
        while (argv[i][j]) {
            
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
            j++;
        
        }
    }
    
    std::cout << std::endl;
	return 0;
}
