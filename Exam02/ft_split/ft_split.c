#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	int	i, s, w;
	int	word_count;
	char	**mat;
	
	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n')
		&& str[i + 1] != '\0')
		{
			word_count++;
		}
		i++;
	}
	mat = (char **)malloc(word_count * sizeof(char *));
	i = 0;
	while (i <= word_count)
	{	
		w = i + 1;
		s = 0;

		mat[i] = (char *)malloc(5 * sizeof(char));

		while (str[s] != '\0'
		&& (str[s + 1] != ' ' || str[s + 1] != '\t' || str[s + 1] != '\n'))
		{
			mat[i][w] = str[s];
			write(1, &mat[i][w], 1);
			s++;
			w++;
		}
		if (str[s] != '\0')
			str[s] = '\0';
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	ft_split("Hello World !");
}
