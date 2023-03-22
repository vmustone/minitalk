/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:29:17 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/21 20:35:01 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & 1) == 0)
			kill(pid, SIGUSR1);
		if ((c & 1) == 1)
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
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
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
		ft_printf("./client, PID, message\n");
	return (0);
}
