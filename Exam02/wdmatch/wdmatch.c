#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s2[k] != '\0')
	{
		if (s1[i] == s2[k])
			i++;
		k++;
	}
	if (s1[i] == '\0')
		ft_putstr(s1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);	
}
