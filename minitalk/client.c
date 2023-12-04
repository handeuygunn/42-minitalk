#include "minitalk.h"

void	send_char(char character, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((character >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write (1, "dogru pid girmedin!", 19);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write (1, "dogru pid girmedin!", 19);
				exit(1);
			}
		}
		i--;
		usleep(100);
	}
}

void	send_string(const char *message, pid_t pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	x;
	
	if (argc != 3)
	{
		write(1, "2 parametre girmeniz gerek", 26);
		exit(1);
	}
	else
	{
		x = ft_atoi(argv[1]);
		send_string(argv[2], x);
	}
	return (0);
}
