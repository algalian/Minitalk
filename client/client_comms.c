/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_comms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:18:52 by algalian          #+#    #+#             */
/*   Updated: 2024/01/29 18:18:54 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	send_sig(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		ft_printf("Error sending signal. Error 3\n");
		exit(3);
	}
	usleep(100);
}

static void	fill_zeros(char c, pid_t pid)
{
	int	n;

	n = 6;
	while (c < ft_pow(2, n))
	{
		send_sig(pid, SIGUSR2);
		n--;
	}
}

void	send_size(int size, pid_t pid)
{
	int	i;

	while (size >= 1)
	{
		if (size % 2 == 0)
			send_sig(pid, SIGUSR2);
		if (size % 2 == 1)
			send_sig(pid, SIGUSR1);
		size /= 2;
	}
	i = 0;
	while (i < 7)
	{
		send_sig(pid, SIGUSR2);
		i++;
	}
}

void	send_seq(char *s, char *t, pid_t pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] >= 1)
		{
			if ((int)s[i] % 2 == 0)
				send_sig(pid, SIGUSR2);
			if ((int)s[i] % 2 == 1)
				send_sig(pid, SIGUSR1);
			s[i] /= 2;
		}
		if (t[i] < 64)
			fill_zeros(t[i], pid);
		i++;
	}
}
