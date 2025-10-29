/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:27:27 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/29 06:42:06 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    
    Bureaucrat* c = 0;
    try {
        std::cout << "=====BUREAUCRAT BOUNDARIES TESTS=====" << std::endl;
        std::cout << std::endl;
        
        Bureaucrat a("Leanne", 1);
        std::cout << std::endl;
        
        Bureaucrat b("Alexandre", 150);
        std::cout << std::endl;
        
        c = new Bureaucrat("Seyf", 2);
        std::cout << std::endl;

        std::cout << "=====PROMOTE BUREAUCRAT TESTS=====" << std::endl;
        std::cout << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        std::cout << std::endl;
    
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

        std::cout << "=====FORM CONSTRUCTOR TESTS=====" << std::endl;
        std::cout << std::endl;
        
        Form f1("Contract", 50, 20);
        std::cout << std::endl;
        
        Form f2("Top Secret", 1, 1);
        std::cout << std::endl;
        
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << std::endl;

        std::cout << "=====CAN SIGNFORM TESTS=====" << std::endl;
        std::cout << std::endl;
        
        c->signForm(f1);
        std::cout << *c << std::endl;
        c->signForm(f1);
        std::cout << std::endl;
        a.signForm(f1);
        std::cout << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.signForm(f2);
        std::cout << std::endl;
               
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << std::endl;

        std::cout << "=====CANNOT SIGNFORM TESTS=====" << std::endl;
        std::cout << std::endl;

        b.signForm(f1);
        std::cout << b << std::endl;
        b.signForm(f2);
        std::cout << std::endl;

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << std::endl;

        std::cout << "===== FORM COPY CTOR =====" << std::endl;
        std::cout << std::endl;
        Form original("Orig", 40, 40);
        a.signForm(original);
        Form copied(original);
        std::cout << "original: " << original << std::endl;
        std::cout << "copied:   " << copied   << std::endl;
        std::cout << std::endl;

        std::cout << "===== EQUALITY SIGN-GRADE =====" << std::endl;
        std::cout << std::endl;
        Bureaucrat eq("Eq", 50);
        Form eqForm("EqForm", 50, 100);
        eq.signForm(eqForm);
        std::cout << std::endl;

        std::cout << "=====DESTRUCTOR TESTS=====" << std::endl;
        std::cout << std::endl;

        // ===== BUREAUCRAT LIMITS EXCEEDED TESTS =====
        // Bureaucrat d("Ilyana", 0);
        // Bureaucrat e("Soraya", 151);

        // ===== FORM LIMITS EXCEEDED TESTS =====
        // Form bad1("Bad1", 0 , 42);
        // Form bad2("Bad2", 42, 151);
    }
    catch (const std::exception& e) {
        std::cout << "Error detected : " << e.what() << std::endl;
    }
    delete c;
    return 0;
}
