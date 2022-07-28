/*#include <unistd.h>

int	duplicate_check(char *s1, char c, int i)
{
	int	k;
	
	k = 0;
	while (k < i)
	{
		if(s1[i] == c)
			return (0);
		k++;
	}
	return (1);
}

void	inter(char *s1, char *s2)
{
	int	i;
	int	k;
	
	i = 0;
	while (s1[i] != '\0')
	{
		k = 0;
		while (s2[k] != '\0')
		{
			if (s1[i] == s2[k] && duplicate_check(s1, s1[i], i) == 1)
			{
				write(1, &s1[i], 1);
				break ;
			}
			k++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return  (0);
}*/


#include <unistd.h>

int		check_doubles(char *str, char c, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
void	inter(char *str, char *str1)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str1[j] != '\0')
		{
			if (str[i] == str1[j])
			{
				if (check_doubles(str, str[i], i) == 1)
				{
					write(1, &str[i], 1);
					break;
				}
			}
			j++;
		}
		i++;
	}
}
int		main(int ac, char **av)
{

	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
