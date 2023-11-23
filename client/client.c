#include"../minitalk.h"

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

void send_seq(int signum, siginfo_t *info, void *context)
{
	static int i;
	//static int first;
	
	if(s[i])
	{
		if(s[i] >= 1)
		{
			if((int)s[i] % 2 == 0)
				kill(info->si_pid, SIGUSR2);
			if((int)s[i] % 2 == 1)
				kill(info->si_pid, SIGUSR1);
			ft_printf("%i\n", i);
			s[i] /= 2;
		}
		i++;
	}	
}

int main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction sa;

	if(argc != 3)
	{
		ft_printf("Wrong number of arguments. Error 1\n");
		return(1);
	}
	pid = ft_atoi(argv[1]);
	num_ok(argv[1]);
	s = argv[2];
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &send_seq;
	sigaction(SIGUSR1, &sa, NULL);
	if((int)s[0] % 2 == 0)
		kill(pid, SIGUSR2);
	if((int)s[0] % 2 == 1)
		kill(pid, SIGUSR1);
	while(1)
	{
		pause();
	}
	return(0);
}