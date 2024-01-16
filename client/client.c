/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:02:33 by algalian          #+#    #+#             */
/*   Updated: 2023/12/14 19:02:35 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	num_ok(char *str)
{
	int	i;

	if (ft_atoi(str) <= 0)
	{
		ft_printf("PID must be a positive numeric value. Error 2\n");
		exit(2);
	}
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
		{
			ft_printf("PID must be a positive numeric value. Error 2\n");
			exit(2);
		}
		i++;
	}
}

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

static void send_size(int size, pid_t pid)
{
	int i;
	
	while(size >= 1)
	{
		if (size % 2 == 0)
			send_sig(pid, SIGUSR2);
		if (size % 2 == 1)
			send_sig(pid, SIGUSR1);
		size /= 2;
	}
	i = 0;
	while(i < 7)
	{	
		send_sig(pid, SIGUSR2); 
		i++;
	}
}

static void	send_seq(char *s, char *t, pid_t pid)
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

int	main(int argc, char **argv)
{
	char	*s;
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments. Error 1\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	num_ok(argv[1]);
	s = ft_strdup(argv[2]);
	send_size(ft_strlen(s), pid);
	send_seq(s, argv[2], pid);
	ft_printf("string terminated\n");
	return (0);
}
