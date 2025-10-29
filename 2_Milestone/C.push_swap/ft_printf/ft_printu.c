/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:03 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/18 17:56:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(unsigned int value, int *counter)
{
	if (value >= 10)
		ft_printu(value / 10, counter);
	ft_putchar((value % 10) + '0');
	(*counter)++;
}
