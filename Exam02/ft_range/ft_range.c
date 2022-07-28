#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*ft_range(int start, int end)
{
	int	a, i, *arr;
	
	a = (start) - (end);
	if (a < 0)
		a = -a;
	a++;	
	arr = (int *)malloc(a * sizeof(int));
	
	i = 0;
	if (start < end)
	{
		while (start <= end )
		{
			arr[i] = start;
			char c = start + 48;
			write(1, &c, 1);
			i++;
			start++;
		}
	}
	else
	{
		while (end <= start)
		{
			arr[i] = start;
			char c = start + 48;
			write(1, &c, 1);
			i++;
			start--;
		}
	}
	return arr;
}

int	main(void)
{
	int *p;
	p = ft_range(1, 5);
	//ft_range(0, -1);
	//ft_range(-1, 2);
	printf("%ls", p);
}
