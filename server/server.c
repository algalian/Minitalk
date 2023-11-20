#include"../minitalk.h"

static void handle_signal(int signum)
{
	static int c;
	
	if(signum == SIGUSR1)
	{
		ft_printf("%i", c);
		c++;
	}
	if(signum == SIGUSR2)
	{
		c = c + 32;
		ft_printf("%c\n", (char) c);
		c = 0;
	}
}

void action()
{


}
int main()
{
	struct sigaction sa;

	ft_printf("%i\n",  getpid());
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1,&sa,NULL);
	while(1)
	{
		pause();
	}
	return(0);
}