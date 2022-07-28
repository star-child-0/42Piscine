#include <unistd.h>

int	check_str(char *str, char c, int i)
{
	int	k;
	
	k = 0;
	while (k < i)
	{
		if (str[k] == c)
			return (0);
		k++;
	}
	return (1);
}

int	ft_strslen(char *s1, char *s2)
{
	int	i;
	int	k;
	
	i = 0;
	k = 0;
	while(s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
		k++;
	return (i + k);
}

char	*ft_strcat(char *s1, char *s2, int size)
{
	int	i;
	int	k;
	char	arr[size];
	char	*p;
	
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		arr[i] = s2[k];
		i++;
		k++;
	}
	p = arr;
	return (p);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	size;
	char	*arr;

	i = 0;
	size = ft_strslen(s1, s2);
	arr = ft_strcat(s1, s2, size);
	while (arr[i] != '\0')
	{
		if (check_str(arr, arr[i], i) == 1)
			write(1, &arr[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}
