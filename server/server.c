#include"../minitalk.h"


static void handle_signal(int signum, siginfo_t *info, void *context)
{
	static int i;
	static int c;
	
	if(i < 7)
	{
		if(signum == SIGUSR1)
		{	
			c += ft_pow(2, i);
		}
		i++;
	}
	if(i >= 7)
	{
		i = 0;
		ft_printf("%c", (char) c);
		c = 0;
	}
	kill(info->si_pid,SIGUSR1);
}


int main()
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%i\n",  getpid());
	while(1)
	{
		pause();
	}
	return(0);
}