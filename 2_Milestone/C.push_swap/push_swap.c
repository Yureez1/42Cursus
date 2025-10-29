/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:53 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 14:28:41 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two(t_list **stack_a)
{
	int		first;
	int		last;
	t_list	*tmp;

	tmp = (*stack_a);
	first = (int)(__intptr_t)(tmp->content);
	tmp = tmp->next;
	last = (int)(__intptr_t)(tmp->content);
	if (first > last)
		sa(stack_a, 0);
}

void	push_three(t_list **stack_a)
{
	int	first;
	int	mid;
	int	last;

	first = (int)(__intptr_t)((*stack_a)->content);
	mid = (int)(__intptr_t)((*stack_a)->next->content);
	last = (int)(__intptr_t)((*stack_a)->next->next->content);
	if (mid > first && mid > last && last > first)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	if (first > mid && mid < last && last > first)
		sa(stack_a, 0);
	if (first > mid && mid < last && last < first)
		ra(stack_a, 0);
	if (mid > last && mid > first && last < first)
		rra(stack_a, 0);
	if (first > mid && mid > last && first > last)
	{
		ra(stack_a, 0);
		sa(stack_a, 0);
	}
	return ;
}

void	push_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*stack_a)->content == min_nbr)
		pb(stack_a, stack_b);
	else if ((int)(__intptr_t)(*stack_a)->next->content == min_nbr)
	{
		ra(stack_a, 0);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((int)(__intptr_t)(*stack_a)->content != min_nbr)
			rra(stack_a, 0);
		pb(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_three(stack_a);
	pa(stack_a, stack_b);
}

void	push_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*stack_a)->content == min_nbr)
		pb(stack_a, stack_b);
	else if ((int)(__intptr_t)(*stack_a)->next->content == min_nbr)
	{
		ra(stack_a, 0);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((int)(__intptr_t)(*stack_a)->content != min_nbr)
			rra(stack_a, 0);
		pb(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	start;
	int	end;
	int	len;

	len = ft_lstsize(*stack_a);
	start = 0;
	end = 15;
	if (len == 1)
		return ;
	else if (len == 2)
		push_two(stack_a);
	else if (len == 3)
		push_three(stack_a);
	else if (len == 4)
		push_four(stack_a, stack_b);
	else if (len == 5)
		push_five(stack_a, stack_b);
	else if (len > 3)
		push_more(stack_a, stack_b, &start, &end);
}
