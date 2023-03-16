/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:59:05 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/24 23:24:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calculate_nbr_base(int nbr, char *base, int size)
{
	char			c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			calculate_nbr_base((2147483648 / size), base, size);
			c = base[2147483648 % size];
			write(1, &c, 1);
		}
		else
			nbr = -nbr;
	}
	if (nbr >= size)
		calculate_nbr_base((nbr / size), base, size);
	c = base[nbr % size];
	write(1, &c, 1);
}

int	check_repetition(char *str, char c, int i)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0')
		return ;
	while (base[i] != '\0')
	{	
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| !check_repetition(base, base[i], i))
			return ;
		i++;
	}
	calculate_nbr_base(nbr, base, i);
}
