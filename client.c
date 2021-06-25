/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:50:33 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/25 13:25:55 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	decimal_to_binary(int n)
{
	long long	bin;
	int			base;
	int			tmp;

	base = 1;
	bin = 0;
	while (n != 0)
	{
		tmp = n % 2;
		n /= 2;
		bin += tmp * base;
		base *= 10;
	}
	return (bin);
}

void	send_my_bin(int bin, int pid)
{
	char	*s_bin;
	int		i;
	int		l_bin;

	i = 0;
	s_bin = ft_itoa(bin);
	l_bin = ft_strlen(s_bin);
	while (l_bin < 8)
	{
		kill(pid, SIGUSR1);
		l_bin++;
		usleep(100);
	}
	while (s_bin[i])
	{
		if (s_bin[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
	free(s_bin);
}

int	main(int argc, char **argv)
{
	int			pid;
	char		*s;
	int			i;
	int			bin;

	i = 0;
	pid = ft_atoi(argv[1]);
	s = ft_strdup(argv[2]);
	if (argc != 3)
	{
		ft_putstr("INVALID NUMBER OF ARGS");
		exit(0);
	}
	while (s[i])
	{
		bin = decimal_to_binary(s[i]);
		send_my_bin(bin, pid);
		i++;
	}
	bin = decimal_to_binary('\n');
	send_my_bin(bin, pid);
	free(s);
}
