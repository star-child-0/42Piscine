#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;
	
	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	main(void)
{
	int	i = ft_atoi("   ---++--+--+++173851few34");
	printf("%d", i);
}
