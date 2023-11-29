#include"../minitalk.h"

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
void send_seq(pid_t pid, char *s)
{
	static int i;

	while(s[i])
	{
		while(s[i] >= 1)
		{
			if((int)s[i] % 2 == 0)
				if(kill(pid, SIGUSR2) == -1)
				{
					ft_printf("error sending signal\n");
					exit(4);
				}
				usleep(100);
			if((int)s[i] % 2 == 1)
				if(kill(pid, SIGUSR1) == -1)
				{
					ft_printf("error sending signal\n");
					exit(4);
				}
				usleep(100);
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
	num_ok(argv[1]);
	send_seq(pid, argv[2]);
	ft_printf("string terminated \n");	
	return(0);
}