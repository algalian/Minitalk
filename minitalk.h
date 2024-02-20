/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:21:44 by algalian          #+#    #+#             */
/*   Updated: 2023/12/14 19:21:46 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct log
{
    int c;
    int j;
    int i;
}	t_log;

void	send_seq(char *s, char *t, pid_t pid);
void	send_size(int size, pid_t pid);

#endif
