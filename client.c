/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:29:17 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/30 19:23:37 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c, int max_bit)
{
	int	bit;

	bit = 0;
	while (bit < max_bit)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bits(pid, ft_strlen(argv[2]), 32);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i], 8);
			i++;
		}
	}
	else
		ft_printf("./client, PID, message\n");
	return (0);
}
