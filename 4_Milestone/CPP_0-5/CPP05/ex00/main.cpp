/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:21:47 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/26 16:58:42 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    
    Bureaucrat* c = 0;
    try {
        std::cout << "=====CREATING BUREAUCRAT TESTS=====" << std::endl;
        std::cout << std::endl;
        
        Bureaucrat a("Leanne", 1);
        std::cout << std::endl;
        
        Bureaucrat b("Alexandre", 150);
        std::cout << std::endl;
        
        c = new Bureaucrat("Seyf", 1);
        std::cout << std::endl;

        // UNCOMMENT TO CATCH THE ERROR MESSAGE
        
        // Bureaucrat d("Ilyana", 0);
        // std::cout << std::endl;

        // UNCOMMENT TO CATCH THE ERROR MESSAGE
        
        // Bureaucrat e("Soraya", 151);
        // std::cout << std::endl;

        // UNCOMMENT TO CATCH THE ERROR MESSAGE
        
        // std::cout << "=====BUREAUCRAT SUPERIOR TO GRADE 1 TEST=====" << std::endl;
        // a.incrementGrade();
        // std::cout << a << std::endl;

        // UNCOMMENT TO CATCH THE ERROR MESSAGE
        
        // std::cout << "=====BUREAUCRAT INFERIOR TO GRADE 150 TEST=====" << std::endl;
        // b.decrementGrade();
        // std::cout << b << std::endl;
        
        // TRY TO PROMOTE POINTER =/= ERROR bc GRADE < 1
        
        // std::cout << *c << std::endl;
        // c->incrementGrade();
        
        // PROMOTING BUREAUCRAT TO BETTER GRADE : 150 IS LOWEST
        std::cout << "=====PROMOTE BUREAUCRAT TESTS=====" << std::endl;
        std::cout << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        std::cout << std::endl;
    
        // DOWNGRADING BUREAUCRAT TO LOWER GRADE : 1 IS HIGHEST
        std::cout << "=====DOWNGRADE BUREAUCRAT TESTS=====" << std::endl;
        std::cout << std::endl;
        
        a.decrementGrade();
        std::cout << a << std::endl;
        std::cout << std::endl;
        
        std::cout << "=====COPY AND OPERATOR TESTS=====" << std::endl;
        std::cout << std::endl;

        Bureaucrat f = a;
        std::cout << f << std::endl;

        std::cout << std::endl;
        
        Bureaucrat g(b);
        std::cout << g << std::endl;

        std::cout << std::endl;
        std::cout << "=====DESTRUCTOR TESTS=====" << std::endl;
        std::cout << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Error detected : " << e.what() << std::endl;
    }
    delete c;
    return 0;
}