/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:47 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 16:25:12 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647))
			return (0);
		if ((sign == -1 && res > 2147483648))
			return (0);
		str++;
	}
	return (1);
}

void	check_parameters(char *str, t_list **stack_a, char **tab)
{
	if (!is_integer(str))
		error_msg("Parameter aren't integer or a number.\n", stack_a, tab);
	init_list(str, stack_a, tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	tab = NULL;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i])
			check_parameters(tab[i++], &stack_a, tab);
	}
	else if (argc > 2)
	{
		while (argv[++i])
			check_parameters(argv[i], &stack_a, tab);
	}
	if (!is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_all(tab, &stack_a, &stack_b, argc);
	exit(EXIT_SUCCESS);
	return (0);
}
