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

static int	attach(char *s, char c, int len)
{
	static int	i;
	static int	size;

	if (len > 0)
	{
		size = len;
		return (0);
	}
	s[i] = c;
	if (i + 1 >= size)
	{
		write(1, &s[0], ft_strlen(s));
		i = 0;
		size = 0;
		return (1);
	}
	i++;
	return (0);
}
static void hold(int *a, int signum)
{

	if(signum == SIGUSR1)
	{
		a[2] += ft_pow(2, a[1]);
		a[0] = 0;
		a[1]++;
	}
	if (signum == SIGUSR2)
	{
		a[0]++;
		a[1]++;
	}
}
static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	*a;
	static char	*s;
	
	if(!a)
		a = malloc(sizeof(int) * 3);
	if (a[0] < 7)	
		hold(a, signum);
	if (a[0] == 7)
	{
		s = malloc(sizeof(char) * (a[2] + 1));
		attach(NULL, 0, a[2]);
		a[1] = 0;
		a[2] = 0;
		a[0]++;
		return ;
	}
	if (a[1] < 7 && a[0] >= 7)
	{
		if (signum == SIGUSR1)
			a[2] += ft_pow(2, a[1]);
		a[1]++;
	}
	if (a[1] >= 7 && a[0] >= 7)
	{	
		if (attach(s, a[2], 0) == 1)
		{	
			a[1] = 0;
			a[2] = 0;
			a[0] = 0;
			free(s);
			return ;
		}
		a[2] = 0;
		a[1] = 0;
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
