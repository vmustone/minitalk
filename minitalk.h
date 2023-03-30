/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:32:18 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/30 20:40:41 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_vars
{
	int	bit;
	int	c;
	int	msg_len;
	int	msg_len_know;
}				t_vars;
#endif
