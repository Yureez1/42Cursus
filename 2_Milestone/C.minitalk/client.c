/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:18 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:27:28 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_get_signal;

int	convert_char_to_signal(char c, int pid)
{
	int	bit_index;
	int	wait_counter;

	bit_index = 7;
	while (bit_index >= 0)
	{
		wait_counter = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_get_signal == 0)
		{
			if (wait_counter == 50)
			{
				ft_printf("\033[1;31mNo signal back. Exiting.\033[0m\n");
				exit(1);
			}
			wait_counter++;
			usleep(1000);
		}
		g_get_signal = 0;
		bit_index--;
	}
	return (0);
}

void	handle_signal_response(int signal)
{
	static int	byte_count;

	g_get_signal = 1;
	if (signal == SIGUSR2)
		byte_count++;
	else if (signal == SIGUSR1)
		ft_printf("\033[1;32mNumber of bytes received: %d\n\033[0m", byte_count
			/ 8);
}

int	main(int argc, char **argv)
{
	struct sigaction	signal_action;
	int					i;
	__pid_t				server_pid;

	if (argc < 2)
		return (ft_printf("PID missing\n"), 0);
	if (argc == 2)
		return (ft_printf("String missing\n"), 0);
	if (argc > 3)
		return (ft_printf("Too many arguments\n"), 0);
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		return (ft_printf("Invalid PID\n"), 0);
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_RESTART;
	signal_action.sa_handler = handle_signal_response;
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1)
		ft_printf("Signal Error\n");
	if (sigaction(SIGUSR2, &signal_action, NULL) == -1)
		ft_printf("Signal Error\n");
	i = 0;
	while (argv[2][i])
		convert_char_to_signal(argv[2][i++], server_pid);
	convert_char_to_signal('\0', server_pid);
	return (0);
}
