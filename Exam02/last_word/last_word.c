#include <unistd.h>

void	ft_putstr(char *str, int i)
{
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	last_word(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	i;
	while (i > 0)
	{
		if (str[i - 1] == ' ' || str[i - 1] == '\t')
		{	
			ft_putstr(str, i);
			break ;
		}
		i--;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
