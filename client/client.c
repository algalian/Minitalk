#include"../minitalk.h"

int ack;

void num_ok(char *str)
{
	int i;

	if(ft_atoi(str) <= 0)
	{
		ft_printf("PID must be a positive numeric value. Error 2\n");
		exit(2);
	}
	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) != 1 )
		{
			ft_printf("PID must be a positive numeric value\n. Error 3\n");
			exit(3);
		}
		i++;
	}
}

static void timer(void)
{
	unsigned int sec;
	
	sec = 0;
	while(ack == 0)
	{
		usleep(1);
		sec++;
		if(sec > 2000000)
		{	
			ft_printf("Timeout. No one is listening. Error 5\n");	
			exit(5);
		}
	}
	ack = 0;
}

static void acknowledged(int signum, siginfo_t *info, void *context)
{	
	ack = 1;
}

static void fill_zeros(char c, pid_t pid)
{
	int n;

	n = 6;
	while(c < ft_pow(2, n))
	{
		if(kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending signal. Error 4\n");
			exit(4);
		}
		n--;
	}
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
	s = ft_strdup(argv[2]);
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
					ft_printf("Error sending signal. Error 4\n");
					exit(4);
				}
			}
			if((int)s[i] % 2 == 1)
			{	
				if(kill(pid, SIGUSR1) == -1)
				{
					ft_printf("Error sending signal. Error 4\n");
					exit(4);
				}
			}
			s[i] /= 2;
			timer();
		}
		if(argv[2][i] < 64)
		{
			fill_zeros(argv[2][i], pid);
			timer();
		}
		i++;
	}
	ft_printf("string terminated\n");	
	return(0);
}
