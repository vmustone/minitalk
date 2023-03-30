/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:38:18 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/30 21:33:07 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_byte_amount;

int	init(t_vars *vars)
{
	vars->bit = 0;
	vars->c = 0;
	vars->msg_len = 0;
	vars->msg_len_know = 0;
	return (1);
}

int	string_save(int c, t_vars *vars)
{
	static char	*string;

	if (g_byte_amount == 0)
	{
		string = malloc(vars->msg_len + 1);
		if (!string)
			return (1);
		string[g_byte_amount] = c;
		g_byte_amount++;
		string[vars->msg_len] = '\0';
		return (0);
	}
	string[g_byte_amount] = c;
	g_byte_amount++;
	if (g_byte_amount == vars->msg_len)
	{
		ft_printf("%s\n", string);
		free(string);
	}
	return (0);
}

void	bits(t_vars *vars)
{
	if (string_save(vars->c, vars) == 1)
		exit(1);
	if (g_byte_amount == vars->msg_len)
	{
		g_byte_amount = 0;
		vars->msg_len_know = 0;
		vars->msg_len = 0;
	}
	vars->bit = 0;
	vars->c = 0;
}

void	signal_handler(int signal)
{
	static int	i;
	t_vars		vars;

	if (i == 0)
		i += init(&vars);
	if (signal == SIGUSR1 && vars.msg_len_know == 1)
		vars.c |= (0x01 << vars.bit);
	else if (signal == SIGUSR1 && vars.bit < 32 && vars.msg_len_know == 0)
		vars.msg_len |= (0x01 << vars.bit);
	vars.bit++;
	if (vars.bit == 32 && vars.msg_len_know == 0)
	{
		vars.bit = 0;
		if (vars.msg_len == 0)
		{
			ft_printf("\n");
			return ;
		}
		vars.msg_len_know = 1;
	}
	if (vars.bit == 8 && vars.msg_len_know == 1)
		bits(&vars);
}

int	main(int argc, char **argv)
{
	if (argc != 1 && argv[0])
	{
		ft_printf("./server\n");
		return (0);
	}
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (argc == 1)
		pause();
	return (0);
}
