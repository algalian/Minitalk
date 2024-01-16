/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:06:13 by algalian          #+#    #+#             */
/*   Updated: 2023/12/14 19:06:14 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


static int attach(char *s, char c, int len)
{
	static int i;
	static int size;

	if(len > 0)
	{
		size = len;
		return(0);
	}
	s[i] = c;
	if(i + 1 >= size)
	{
		write(1, &s[0], ft_strlen(s));
		i = 0;
		size = 0;
		return(1);
	}
	i++;
	return(0);
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		i;
	static int		j;
	static int		c;
	static char		*s;

	if (signum == SIGUSR1 && j < 7)
	{
		c += ft_pow(2, i);
		j = 0;
		i++;
		return;
	}
	if (signum == SIGUSR2  && j < 7)
	{
		j++;
		i++;
	}
	if (j == 7)
	{	
		s = malloc(sizeof(char) *  (c + 1));
		attach(NULL, 0, c);
		i = 0;
		c = 0;
		j++;
		return;
	}	
	if (i < 7 && j >= 7)
	{
		if (signum == SIGUSR1)
		{
			c += ft_pow(2, i);
		}
		i++;
	}
	if (i >= 7 && j >= 7)
	{
		if(attach(s, c, 0) == 1)
		{
			i = 0;
			c = 0;
			j = 0;
			free(s);
			return;
		}
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%i\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
