/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:49:43 by jbanchon          #+#    #+#             */
/*   Updated: 2024/06/13 12:46:20 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_putstr(char *value, int *counter)
{
	int	i;

	i = 0;
	if (value == 0)
		value = "(null)";
	while (value[i] != '\0')
	{
		ft_putchar(value[i]);
		i++;
		(*counter)++;
	}
	return (*counter);
}
