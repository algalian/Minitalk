#include"../minitalk.h"

int num_ok(char *s)
{
	int i;

	if(ft_atoi(s) <= 0)
	{
		ft_printf("PID must be a positive numeric value. Error 3\n");
		exit(2);
	}
	i = 0;
	while(s[i])
	{
		if(ft_isdigit(s[i]) != 1 )
		{
			ft_printf("PID must be a positive numeric value\n. Error 4\n");
			exit(3);
		}
		i++;
	}
	return(0);
}

void signal_seq(pid_t pid, char *s)
{
	int i;
	
	i = 0;
	while(s[i])
	{
		while(s[i] >= 1)
		{
			if((int)s[i] % 2 == 0)
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}
			if((int)s[i] % 2 == 1)
			{
				kill(pid, SIGUSR1);
				usleep(50);
			}
			s[i] /= 2;
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	pid_t pid;

	if(argc != 3)
	{
		ft_printf("Wrong number of arguments. Error 1\n");
		return(1);
	}
	pid = ft_atoi(argv[1]);
	if (num_ok(argv[1]) == 0)
	{
		signal_seq(pid, argv[2]);
	}
	else
	{
		ft_printf("Error sending signal. Error 5\n");
		return(5);
	}	
	return(0);
}