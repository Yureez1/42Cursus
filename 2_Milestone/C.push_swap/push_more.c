/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:51 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 15:10:27 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*cur;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	cur = (*stack);
	while ((int)(__intptr_t)cur->content < (int)(__intptr_t)cur->next->content)
	{
		if (cur->next->next == NULL)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	push_next(t_list **stack_a, t_list **stack_b)
{
	int		half;
	t_list	*cur;

	cur = NULL;
	while (*stack_b)
	{
		cur = find_max(stack_b);
		half = find_half(stack_b, (int)(__intptr_t)cur->content,
				(ft_lstsize(*stack_b) / 2));
		while ((int)(__intptr_t)(*stack_b)->content != (int)(__intptr_t)cur->content)
		{
			if (half == 1)
				rb(stack_b, 0);
			else
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b);
	}
}

void	push_more(t_list **stack_a, t_list **stack_b, int *start, int *end)
{
	int	len;

	len = ft_lstsize(*stack_a);
	init_index(stack_a, len);
	while (*stack_a)
	{
		if ((*stack_a)->index <= (*start))
		{
			pb(stack_a, stack_b);
			rb(stack_b, 0);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index > (*start) && (*stack_a)->index < (*end))
		{
			pb(stack_a, stack_b);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index >= (*end))
			ra(stack_a, 0);
	}
	push_next(stack_a, stack_b);
}
