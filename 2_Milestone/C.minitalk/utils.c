/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:13 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:28:09 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_message(t_list **msg)
{
	t_list	*current;

	current = *msg;
	while (current)
	{
		ft_printf("%c", *(char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	free_all(t_list **msg)
{
	t_list	*temp;

	while ((*msg))
	{
		temp = *msg;
		free((*msg)->content);
		(*msg)->content = NULL;
		*msg = (*msg)->next;
		free(temp);
		temp = NULL;
	}
}
