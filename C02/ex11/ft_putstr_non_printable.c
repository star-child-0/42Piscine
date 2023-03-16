/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:32:46 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/20 22:24:47 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hex(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putchar(n / 16);
		ft_putchar(hex[n % 16]);
	}
	else
		ft_putchar(hex[n]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 31) || str[i] == 127)
		{
			ft_putchar(92);
			if (str[i] < 16)
				ft_putchar('0');
			ft_put_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
