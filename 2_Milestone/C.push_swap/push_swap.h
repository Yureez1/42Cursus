/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:55 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 16:25:12 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>

// typedef struct s_data
// {
// 	int				content;
// 	int				index;
// 	struct s_data	*next;
// }					t_list;

void				error_msg(char *str, t_list **stack_a, char **tab);
void				free_all(char **tab, t_list **stack_a, t_list **stack_b,
						int argc);
void				init_list(char *argv, t_list **stack_a, char **tab);
void				push_swap(t_list **stack_a, t_list **stack_b);

int					find_half(t_list **stack, int max, int len);
t_list				*find_max(t_list **stack);
t_list				*find_min(t_list **stack);
void				init_index(t_list **stack_a, int len);
void				index_zero(t_list **stack);
int					is_sorted(t_list **stack);



void				push_more(t_list **stack_a, t_list **stack_b, int *start,
						int *end);
void				push_next(t_list **stack_a, t_list **stack_b);

/***************
******SWAP******
****************/

void				sa(t_list **stack_a, int flag);
void				sb(t_list **stack_b, int flag);
void				ss(t_list **stack_a, t_list **stack_b);

/***************
******PUSH******
****************/

void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);

/**************
****REVERSE****
***************/

void				ra(t_list **stack_a, int flag);
void				rb(t_list **stack_b, int flag);
void				rr(t_list **stack_a, t_list **stack_b);

/***************
*REVERSE_ROTATE*
****************/

void				rrr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a, int flag);
void				rrb(t_list **stack_b, int flag);

#endif