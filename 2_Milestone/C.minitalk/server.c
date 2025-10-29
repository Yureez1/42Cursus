/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:02:12 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:27:21 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_signal_to_bit(int signal, char *character_byte)
{
	if (signal == SIGUSR1)
		*character_byte = (*character_byte << 1) | 1;
	else if (signal == SIGUSR2)
		*character_byte = *character_byte << 1;
}

int	create_msg_node(t_list **msg_list, char c)
{
	t_list	*new_node;
	char	*c_adress;

	c_adress = malloc(sizeof(char));
	if (!c_adress)
		return (free_all(msg_list), ft_printf("Malloc Error\n"), 0);
	*c_adress = c;
	new_node = ft_lstnew(c_adress);
	if (!new_node)
	{
		free(c_adress);
		return (free_all(msg_list), ft_printf("Node Error\n"), 0);
	}
	ft_lstadd_back(msg_list, new_node);
	return (1);
}

void	handle_incoming_signal(int signal, siginfo_t *client_info,
		void *context)
{
	static int		client_pid;
	static int		bit_count;
	static char		current_character;
	static t_list	*msg;

	(void)context;
	if (client_pid == 0)
		client_pid = client_info->si_pid;
	convert_signal_to_bit(signal, &current_character);
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (!current_character)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			print_message(&msg);
			free_all(&msg);
			return ;
		}
		if (!create_msg_node(&msg, current_character))
			return ;
		current_character = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	int					server_pid;
	struct sigaction	signal_action;

	server_pid = getpid();
	ft_printf("\033[1;32mServer PID: %d\n\033[0m", server_pid);
	ft_printf("\033[1;34mServer is ready. Waiting for messages...\033[0m\n");
	signal_action.sa_flags = SA_RESTART | SA_SIGINFO;
	signal_action.sa_sigaction = handle_incoming_signal;
	sigemptyset(&signal_action.sa_mask);
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1)
		ft_printf("Signal Error\n");
	if (sigaction(SIGUSR2, &signal_action, NULL) == -1)
		ft_printf("Signal Error\n");
	while (1)
		pause();
	return (0);
}
