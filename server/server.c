#include"../minitalk.h"

static void	handle_signal()
{
	ft_printf("flag seen!\n");
	exit(0);
}


int main()
{
	pid_t pid;

	signal(SIGUSR1, &handle_signal);
	pid = getpid();
	ft_printf("Process %i listening...\n",pid);
	while(1)
	{
		sleep(1);
	}
	return(0);
}