#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

int		ft_atoi(const char *s);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_strdup(char *s1);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const c);
void	ft_putstr(char *s);

#endif