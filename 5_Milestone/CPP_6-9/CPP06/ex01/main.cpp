/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:42:19 by julien            #+#    #+#             */
/*   Updated: 2025/10/16 08:42:39 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    try {
        Data data;
        data.id = 1;
        data.name = "Random";
        data.score = 42.42;

        std::cout << "Original Data address: " << &data << std::endl;

        uintptr_t raw = Serializer::serialize(&data);
        std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

        std::cout << std::endl;

        Data* ptr = Serializer::deserialize(raw);
        std::cout << "Deserialized address: " << ptr << std::endl;

        std::cout << "Data content after deserialization:" << std::endl;
        std::cout << "  id: " << ptr->id << std::endl;
        std::cout << "  name: " << ptr->name << std::endl;
        std::cout << "  score: " << ptr->score << std::endl;

        ptr->score += 0.58;
        std::cout << "After" << std::endl;
        std::cout << "score = " << data.score << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << " Exception caught: " << e.what() << std::endl;
        return 1;
    }
}
