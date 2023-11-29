#include"../minitalk.h"

volatile int ack;

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
	static int	i;
	
	ack = 1;
	i++;
	ft_printf("counter signal received %i\n", i);
	
}

int main(int argc, char **argv)
{
	char *s;
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
	ft_printf("%s\n", s);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &acknowledged;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while(s[i])
	{
		while(s[i] >= 1)
		{
			if((int)s[i] % 2 == 0)
			{
				if(kill(pid, SIGUSR2) == -1)
				{
					ft_printf("error sending signal\n");
					exit(4);
				}
			if((int)s[i] % 2 == 1)
			{
				if(kill(pid, SIGUSR1) == -1)
				{
					ft_printf("error sending signal\n");
					exit(4);
				}
			s[i] /= 2;
		}
		if(s[i] <= 1)
			i++;
		ack = 0;
		while(ack == 0)
			pause();
	}
	ft_printf("string terminated \n");	
	return(0);
}