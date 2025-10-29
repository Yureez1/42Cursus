/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:05 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 14:24:26 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_zero(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

void	init_index(t_list **stack_a, int len)
{
	t_list	*tmp;
	t_list	*current;
	int		min;
	int		i;

	index_zero(stack_a);
	i = 1;
	while (len > 0)
	{
		min = INT32_MAX;
		current = *stack_a;
		while (current)
		{
			if ((int)(__intptr_t)current->content < min && current->index == 0)
			{
				min = (int)(__intptr_t)current->content;
				tmp = current;
			}
			current = current->next;
		}
		tmp->index = i;
		i++;
		len--;
	}
}

t_list	*find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min_node;
	int		min;

	min = INT32_MAX;
	tmp = *stack;
	min_node = NULL;
	while (tmp)
	{
		if ((int)(__intptr_t)tmp->content < min)
		{
			min = (int)(__intptr_t)tmp->content;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_list	*find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max_node;
	int		max;

	max = INT32_MIN;
	tmp = *stack;
	max_node = NULL;
	while (tmp)
	{
		if ((int)(__intptr_t)tmp->content > max)
		{
			max = (int)(__intptr_t)tmp->content;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

int	find_half(t_list **stack, int max, int len)
{
	t_list	*current;

	current = *stack;
	while (len > 0 && current)
	{
		if ((int)(__intptr_t)current->content == max)
			return (1);
		current = current->next;
		len--;
	}
	return (0);
}
