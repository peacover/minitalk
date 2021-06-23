/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:50:26 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/23 14:58:21 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include "minitalk_utils.c"
// #include "minitalk_utils2.c"

char	*g_s;

int	binary_to_decimal(int n)
{
	int	dec;
	int	base;
	int	tmp;

	base = 1;
	tmp = 0;
	dec = 0;
	while (n)
	{
		tmp = n % 10;
		n = n / 10;
		dec += tmp * base;
		base = base * 2;
	}
	return (dec);
}

void	handle_usr1(int i)
{
	unsigned int	to_int;

	to_int = 0;
	(void)i;
	g_s = ft_strjoin(g_s, '0');
	if (ft_strlen(g_s) == 8)
	{
		to_int = ft_atoi(g_s);
		ft_putchar(binary_to_decimal(to_int));
		free(g_s);
		g_s = ft_strdup("");
	}
}

void	handle_usr2(int i)
{
	unsigned int	to_int;

	to_int = 0;
	(void)i;
	g_s = ft_strjoin(g_s, '1');
	if (ft_strlen(g_s) == 8)
	{
		to_int = ft_atoi(g_s);
		ft_putchar(binary_to_decimal(to_int));
		free(g_s);
		g_s = ft_strdup("");
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	(void)argc;
	pid = getpid();
	g_s = ft_strdup("");
	signal(SIGUSR1, handle_usr1);
	signal(SIGUSR2, handle_usr2);
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
}
