#include "minitalk.h"

void	ft_handler(int signum)
{
	int		x;
	static int	bit_number = 0;
	static int	result = 0;

	x = 0;
	if (signum == SIGUSR2)
		x = 1;
	result = (result * 2) + x;
	bit_number++;
	if (bit_number == 8)
	{
		write (1, &result, 1);
		bit_number = 0;
		result = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	while (1)
	{
		signal (SIGUSR1, ft_handler);
		signal (SIGUSR2, ft_handler);
		pause();
	}
}
