/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:41:53 by jbanchon          #+#    #+#             */
/*   Updated: 2025/10/16 12:44:49 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename T>
void swap(T& v1, T& v2){
    T v3 = v1;
    v1 = v2;
    v2 = v3;
}

template <typename N>
N const& min(N const& n1, N const& n2) {
    return (n1 < n2 ? n1 : n2);
}

template <typename N>
N const& max(N const& n1, N const& n2) {
    return (n1 > n2 ? n1 : n2);
}


#endif
