/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:38:18 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/22 13:37:19 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	bit;
	static int	i;
	
	if (signal == SIGUSR1)
		i |= 0 << bit;
	else if (signal == SIGUSR2)
		i |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_printf("./server\n");
		return (0);
	}
	ft_printf("PID: %d\n", getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
