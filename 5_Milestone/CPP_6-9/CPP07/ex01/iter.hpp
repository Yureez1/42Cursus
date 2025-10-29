/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:15:54 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/16 12:54:59 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <string>
#include <iostream>

template<typename T, typename Func>
static void iter(T* arr, size_t len, Func f) {
    if (!arr)
        return ;
    for (size_t i = 0; i < len; i++) {
        f(arr[i]);
    }
}

#endif
