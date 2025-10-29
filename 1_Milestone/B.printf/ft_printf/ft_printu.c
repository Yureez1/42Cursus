/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:03 by jbanchon          #+#    #+#             */
/*   Updated: 2024/06/11 13:05:23 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_printu(unsigned int value, int *counter)
{
	if (value >= 10)
		ft_printu(value / 10, counter);
	ft_putchar((value % 10) + '0');
	(*counter)++;
}
