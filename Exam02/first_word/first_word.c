#include <unistd.h>

void first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
		{
		 	write(1, &str[i], 1);
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				break;
		}
		i++;
	}
}

int main (int argc, char *argv[])
{
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
}
