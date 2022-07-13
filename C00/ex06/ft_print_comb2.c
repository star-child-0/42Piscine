/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:30:36 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/13 23:12:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_func(int a, int b)
{
	char	h;
	char	k;

	h = (a / 10) + 48;
	k = (a % 10) + 48;
	ft_putchar(h);
	ft_putchar(k);
	ft_putchar(' ');
	h = (b / 10) + 48;
	k = (b % 10) + 48;
	ft_putchar(h);
	ft_putchar(k);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_func(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
