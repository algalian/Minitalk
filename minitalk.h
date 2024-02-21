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

void	send_seq(char *s, char *t, pid_t pid);
void	send_size(int size, pid_t pid);
int		attach(char *s, char c, int len);
void	hold(int *a, int signum);
char	*define(int *a);
void	guess(int *a, int signum);
void	reset(int *a, char *s);

#endif
