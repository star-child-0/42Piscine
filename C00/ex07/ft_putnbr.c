/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:15:44 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/13 23:25:08 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	val;
	
	if (nb >= 0 && nb <= 9)
	{
		val = nb + 48;
		ft_putchar(val);
	}
	else if (nb >= 10 && nb <= 99)
	{
		val = (nb / 10) + 48;
		ft_putchar(val);
		val = (nb % 10) + 48;
		ft_putchar(val);
	}
}

int	main(void)
{
	ft_putnbr(69);
	return (0);
}
