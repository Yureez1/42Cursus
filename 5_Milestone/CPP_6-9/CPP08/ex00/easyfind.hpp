/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:55:28 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/23 12:59:14 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
#endif
