/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:57:10 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/31 18:57:12 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_Number.h"

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	translate(t_Number *num, char *number);

char	*ft_strcmp(t_Number *num, char *number)
{
	int	i;
	int	j;

	i = 0;
	while (num + i)
	{
		j = 0;
		while (num[i].nb[j] == number[j])
		{
			if (number[j] == '\0')
				return (num[i].word);
			j++;
		}
		i++;
	}
	write(1, "Dict Error\n", 11);
	return (0);
}

int	check_mag_10(char *number, int index, t_Number *num)
{
	char	app[2];

	if (ft_atoi(number + index) > 19)
	{
		app[0] = *(number + index);
		app[1] = '0';
		translate(num, app);
	}
	else if (ft_atoi(number + index) > 9)
	{
		translate(num, number + index);
		return (1);
	}
	return (0);
}

void	check_mag_1(char *number, int index, t_Number *num)
{
	char	app[2];

	if (ft_atoi(number + index) != 0)
	{
		if (ft_atoi(number + index - 1) > 10)
			write(1, "-", 1);
		app[0] = *(number + index);
		app[1] = '\0';
		translate(num, app);
	}
}

void	number_magnitude(t_Number *num, char *number, int index)
{
	int		lenght;
	char	app[2];

	lenght = ft_strlen(number + index);
	if (lenght % 3 == 0 && number[index] != '0')
	{
		app[0] = *(number + index);
		app[1] = '\0';
		ft_putstr(ft_strcmp(num, app));
		write(1, " ", 1);
		ft_putstr(ft_strcmp(num, "100"));
		if (ft_atoi(number + index + 1) != 0)
			write(1, " and ", 5);
	}
	else if (lenght % 2 == 0)
	{
		if (check_mag_10(number, index, num))
			return ;
	}
	else if (lenght == 1)
		check_mag_1(number, index, num);
	if (lenght > 1)
		number_magnitude(num, number, ++index);
}
