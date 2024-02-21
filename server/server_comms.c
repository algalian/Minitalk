/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_comms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:25:58 by algalian          #+#    #+#             */
/*   Updated: 2024/02/21 17:26:01 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	hold(int *a, int signum)
{
	if (signum == SIGUSR1)
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

char	*define(int *a)
{
	char	*s;

	s = malloc(sizeof(char) * (a[2] + 1));
	if (!s)
	{
		ft_printf("malloc error \n");
		exit(1);
	}
	attach(NULL, 0, a[2]);
	a[1] = 0;
	a[2] = 0;
	a[0]++;
	return (s);
}

void	guess(int *a, int signum)
{
	if (signum == SIGUSR1)
		a[2] += ft_pow(2, a[1]);
	a[1]++;
}

int	attach(char *s, char c, int len)
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

void	reset(int *a, char *s)
{
	a[1] = 0;
	a[2] = 0;
	a[0] = 0;
	if (s)
		free(s);
}
