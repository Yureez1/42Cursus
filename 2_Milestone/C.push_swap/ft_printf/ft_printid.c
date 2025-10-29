/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:59 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/18 17:56:39 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(int value)
{
	size_t	length;

	length = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = -value;
		length++;
	}
	while (value != 0)
	{
		value = value / 10;
		length++;
	}
	return (length);
}

void	ft_printid(int value, int *counter)
{
	ft_putnbr_fd(value, 1);
	(*counter) += ft_numlen(value);
}
