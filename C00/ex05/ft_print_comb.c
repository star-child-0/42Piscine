/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:25:13 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/13 22:08:24 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_function(int i, int j, int k)
{
	char	c;

	c = i + 48;
	ft_putchar(c);
	c = j + 48;
	ft_putchar(c);
	c = k + 48;
	ft_putchar(c);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < 8)
	{
		while (j < 9)
		{
			while (k <= 9)
			{
				ft_function(i, j, k);
				k++;
			}
			j++;
			k = j + 1;
		}
		j = i + 1;
		i++;
	}
}
