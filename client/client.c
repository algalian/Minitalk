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

static void	num_ok(char *str)
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
