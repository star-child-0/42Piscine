#include <unistd.h>
void	aff(char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'a')
		{
			write(1, "a", 1);
			break ;
		}
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "a\n" , 2);
	if (argc == 2)
	{
		aff(argv[1]);
	}
}
