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
	static int	i;
	static int	c;

	if (i < 7)
	{
		if (signum == SIGUSR1)
		{
			c += ft_pow(2, i);
		}
		i++;
	}
	if (i >= 7)
	{
		write(1, &c, 1);
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
