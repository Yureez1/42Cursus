/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:45 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 14:30:06 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 
int	is_in_list(t_list *stack_a, int num)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if ((int)(__intptr_t)stack_a->content == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	init_list(char *argv, t_list **stack_a, char **tab)
{
	static t_list	*tmp;
	int				num;

	num = ft_atoi(argv);
	if (is_in_list(*stack_a, num))
		error_msg("There is a parameter twice.", stack_a, tab);
	tmp = ft_lstnew((void *)(__intptr_t)num);
	if (!tmp)
		error_msg("Failed to create new node.", stack_a, tab);
	ft_lstadd_back(stack_a, tmp);
}
