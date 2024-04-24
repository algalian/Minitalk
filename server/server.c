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

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	*a;
	static char	*s;

	if (!a)
		a = malloc(sizeof(int) * 3);
	if (!a[0])
		hold(a, signum);
	if (a[0] == 1)
	{
		s = define(a);
		return ;
	}
	if (a[1] < 7 && a[0] > 1)
		guess(a, signum);
	if (a[1] >= 7 && a[0] > 1)
	{
		if (attach(s, a[2], 0) == 1)
		{
			reset(a, s);
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
