/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:41:03 by jbanchon          #+#    #+#             */
/*   Updated: 2025/09/08 15:01:01 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include "Fixed.hpp"

// // Couleurs ANSI
// #define RESET   "\033[0m"
// #define GREEN   "\033[32m"
// #define RED     "\033[31m"
// #define YELLOW  "\033[33m"
// #define LILA    "\033[1;38;5;206m"
// #define BLUE    "\033[1;34m"

// // Helpers
// static bool approxEq(float a, float b, float eps) { return std::fabs(a - b) <= eps; }
// // Référence Q8 : arrondi au plus proche sur 8 bits fractionnaires
// static float q8(float x) { return std::floor(x * 256.0f + 0.5f) / 256.0f; }

// int main(void) {
//     std::cout.setf(std::ios::fixed);
//     std::cout << std::setprecision(7);

//     const float EPS = 1e-6f;
//     const float LSB = 1.0f / 256.0f;

//     std::cout << GREEN << "================================================================" << RESET << "\n";
//     std::cout << GREEN << "==============================TEST==============================" << RESET << "\n";
//     std::cout << GREEN << "================================================================" << RESET << "\n\n";

//     std::cout << GREEN  << "GOOD RESULT: GREEN"    << RESET << "\n";
//     std::cout << RED    << "BAD RESULT:  RED"      << RESET << "\n";
//     std::cout << YELLOW << "WARNING:     YELLOW"   << RESET << "\n";
//     std::cout << LILA   << "MY RESULT:   LILA"     << RESET << "\n";
//     std::cout << BLUE   << "REFERENCE:   BLUE (Q8)"<< RESET << "\n\n";

//     // ========================= FIXED vs Q8 (opérateurs) =========================
//     std::cout << GREEN << "================================================================" << RESET << "\n";
//     std::cout << GREEN << "=========================FIXED vs Q8 REF=========================" << RESET << "\n";
//     std::cout << GREEN << "================================================================" << RESET << "\n\n";

//     Fixed x(5.05f);
//     Fixed y(2);
//     float fx = 5.05f;
//     float fy = 2.0f;

//     // Références Q8
//     float qx = q8(fx);
//     float qy = q8(fy);
//     float ref_add = qx + qy;          // +/-
//     float ref_sub = qx - qy;
//     float ref_mul = q8(qx * qy);      // */ : re-quantifier le résultat
//     float ref_div = q8(qx / qy);

//     // Affichages + verdicts
//     float got_add = (x + y).toFloat();
//     float got_sub = (x - y).toFloat();
//     float got_mul = (x * y).toFloat();
//     float got_div = (x / y).toFloat();

//     std::cout << LILA << "Fixed +  : " << got_add << RESET
//               << " | " << BLUE << "Q8 + : " << ref_add << RESET
//               << "  " << (approxEq(got_add, ref_add, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     std::cout << LILA << "Fixed -  : " << got_sub << RESET
//               << " | " << BLUE << "Q8 - : " << ref_sub << RESET
//               << "  " << (approxEq(got_sub, ref_sub, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     std::cout << LILA << "Fixed *  : " << got_mul << RESET
//               << " | " << BLUE << "Q8 * : " << ref_mul << RESET
//               << "  " << (approxEq(got_mul, ref_mul, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     std::cout << LILA << "Fixed /  : " << got_div << RESET
//               << " | " << BLUE << "Q8 / : " << ref_div << RESET
//               << "  " << (approxEq(got_div, ref_div, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n\n";

//     // =========================== Séquence du sujet ============================
//     std::cout << GREEN << "================================================================" << RESET << "\n";
//     std::cout << GREEN << "==========================SUJET SEQUENCE=========================" << RESET << "\n";
//     std::cout << GREEN << "================================================================" << RESET << "\n\n";

//     Fixed a;
//     Fixed const b( Fixed(5.05f) * Fixed(2) );

//     // Référence float Q8 pour suivre la même sémantique
//     float af = q8(0.0f);
//     float bf = q8(fx) * q8(fy); // = 10.1015625

//     // 1) a
//     std::cout << LILA << "a         : " << a << RESET
//               << " | " << BLUE << "ref(a)     : " << af << RESET
//               << "  " << (approxEq(a.toFloat(), af, EPS) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 2) ++a
//     float ref_pre = (af += LSB);
//     Fixed pre = ++a;
//     std::cout << LILA << "++a       : " << pre << RESET
//               << " | " << BLUE << "ref(++a)   : " << ref_pre << RESET
//               << "  " << (approxEq(pre.toFloat(), ref_pre, EPS) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 3) a
//     std::cout << LILA << "a         : " << a << RESET
//               << " | " << BLUE << "ref(a)     : " << af << RESET
//               << "  " << (approxEq(a.toFloat(), af, EPS) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 4) a++
//     float shown_post = af;   // valeur affichée côté ref AVANT incrément
//     Fixed post = a++;
//     af += LSB;               // puis on incrémente la ref
//     std::cout << LILA << "a++ (aff) : " << post << RESET
//               << " | " << BLUE << "ref(a++)   : " << shown_post << RESET
//               << "  " << (approxEq(post.toFloat(), shown_post, EPS) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 5) a
//     std::cout << LILA << "a         : " << a << RESET
//               << " | " << BLUE << "ref(a)     : " << af << RESET
//               << "  " << (approxEq(a.toFloat(), af, EPS) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 6) b
//     std::cout << LILA << "b         : " << b << RESET
//               << " | " << BLUE << "ref(b)     : " << bf << RESET
//               << "  " << (approxEq(b.toFloat(), bf, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//     // 7) max(a,b)
//     const Fixed& fmax = Fixed::max(a, b);
//     float ref_max = (af >= bf) ? af : bf;
//     std::cout << LILA << "max(a,b)  : " << fmax << RESET
//               << " | " << BLUE << "ref(max)   : " << ref_max << RESET
//               << "  " << (approxEq(fmax.toFloat(), ref_max, 1e-4f) ? GREEN "[OK]" : RED "[FAIL]") << RESET << "\n";

//             // ======================== Test Division par 0 ========================

//     std::cout << "\n";
//     std::cout << GREEN << "================================================================" << RESET << "\n";
//     std::cout << GREEN << "=========================DIVISION BY ZERO========================" << RESET << "\n";
//     std::cout << GREEN << "================================================================" << RESET << "\n\n";

//     Fixed c(42.0f);
//     Fixed zero(0);

//     std::cout << YELLOW << "Tentative de division par zero (Fixed 42 / Fixed 0)..." << RESET << std::endl;
//     try {
//         Fixed res = c / zero;   // ⚠ ici ça peut crasher
//         std::cout << LILA << "Résultat: " << res << RESET << std::endl;
//     }
//     catch (...) {
//         std::cout << RED << "Exception attrapée !" << RESET << std::endl;
//     }

//     return 0;
// }
