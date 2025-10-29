/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:29:08 by julien            #+#    #+#             */
/*   Updated: 2025/10/14 11:35:44 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
