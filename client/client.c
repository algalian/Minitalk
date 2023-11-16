#include"../minitalk.h"


int main(int argc, char **argv)
{
	pid_t pid_server;
	if(argc != 3)
	{
		ft_printf("Wrong number of arguments");
		return(1);
	}
	pid_server = atoi(argv[1]);
	ft_printf("%s",argv[2]);
	
	kill(pid_server,SIGKILL);
	return(0);
}