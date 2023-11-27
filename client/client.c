#include"../minitalk.h"

int ack;
char *s;

void num_ok(char *str)
{
	int i;

	if(ft_atoi(str) <= 0)
	{
		ft_printf("PID must be a positive numeric value. Error 3\n");
		exit(2);
	}
	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) != 1 )
		{
			ft_printf("PID must be a positive numeric value\n. Error 4\n");
			exit(3);
		}
		i++;
	}
}

static void acknowledged(int signum, siginfo_t *info, void *context)
{
	ack = 1;
}

int main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction sa;
	int i;

	if(argc != 3)
	{
		ft_printf("Wrong number of arguments. Error 1\n");
		return(1);
	}
	pid = ft_atoi(argv[1]);
	num_ok(argv[1]);
	s = argv[2];
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = acknowledged;
	ack = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while(1)
	{
		if(s[i] >= 1)
		{
			if((int)s[i] % 2 == 0)
				kill(pid, SIGUSR2);
			if((int)s[i] % 2 == 1)
				kill(pid, SIGUSR1);
			s[i] /= 2;
		}
		if(s[i] < 1)
			i++;
		if(!s[i])
		{
			ft_printf("string terminated\n");
			exit(0);
		}
		ack = 0;
		while(ack == 0)
		{
			pause();
		}
	}	
	return(0);
}