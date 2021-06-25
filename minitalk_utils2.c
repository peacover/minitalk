/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:49:40 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/25 13:29:14 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	len_int(int n)
{
	int				l;
	unsigned int	nb;

	l = 1;
	if (n < 0)
	{
		l++;
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	while (nb > 9)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int				l;
	char			*s;
	unsigned int	nb;

	l = len_int(n);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (0);
	s[l] = '\0';
	l--;
	if (n >= 0)
		nb = (unsigned int)n;
	else
		nb = (unsigned int)(-n);
	while (l >= 0)
	{
		s[l] = (nb % 10) + '0';
		nb /= 10;
		l--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

char	*ft_strjoin(char const *s1, char const c)
{
	int		len1;
	char	*s3;
	int		i;

	i = 0;
	len1 = 0;
	while (s1[len1])
		len1++;
	s3 = (char *)malloc((len1 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	s3[i++] = c;
	s3[i] = '\0';
	return (s3);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
