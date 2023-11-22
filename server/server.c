#include"../minitalk.h"


static void handle_signal(int signum)
{
	static int i;
	static int c;
	
	while(i < 8)
	{
		c += ft_pow(2, i);
		i++;
	}
	if(i >= 8)
	{
		i = 0;
		ft_printf("%c", (char) c);
		c = 0;
	}
}

int main()
{
	int i;

	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR2, &handle_signal);
	ft_printf("%i\n",  getpid());
	i = 0; 
	while(1)
	{
		pause();
	}
	return(0);
}