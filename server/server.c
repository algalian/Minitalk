#include"../minitalk.h"



int main()
{
	pid_t pid;
	
	pid = getpid();
	ft_printf("Process %i listening...\n",pid);
	while(1)
	{
		sleep(5);
		ft_printf("listening...\n");
	}
	return(0);
}