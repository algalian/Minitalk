#include"../minitalk.h"

int main(int argc, char **argv)
{

	if (kill(ft_atoi(argv[1]), SIGUSR1) == 0)
		ft_printf("flag raised!\n");
	else
		ft_printf("error\n");
	return(0);
}