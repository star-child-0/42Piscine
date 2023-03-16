/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:25:46 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/30 19:25:59 by anvannin         ###   ########.fr       */
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
void	number_magnitude(t_Number *num, char *number, int index);
char	*ft_strcmp(t_Number *num, char *number);

int	print_comma_and_space(int lenght, char *cent)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (cent[i] != '0')
		{
			if (lenght == 3 && cent[0] == '0')
				write(1, " and", 5);
			else
				write(1, ",", 2);
			write(1, " ", 1);
			break ;
		}
	}
	return (i);
}

void	print_b_num_3(int lenght, t_Number *num, int i)
{
	int		tmp;	
	char	*magnitude;

	if (lenght != 3 && i != 3)
	{
		tmp = lenght;
		while ((tmp - 1) % 3 != 0)
			tmp--;
		magnitude = malloc(tmp + 1);
		i = 0;
		magnitude[0] = '1';
		while (++i < tmp)
			magnitude[i] = '0';
		magnitude[i] = '\0';
		write(1, " ", 1);
		ft_putstr(ft_strcmp(num, magnitude));
		free(magnitude);
	}
}

void	print_b_num_2(int lenght, t_Number *num, char *number, int j)
{
	int		i;
	char	*cent;

	cent = malloc(sizeof(char) * 3);
	lenght = ft_strlen(number) - lenght;
	while (lenght % 3 == 0 && lenght != 0)
	{
		i = -1;
		while (++i < 3)
			cent[i] = number[++j];
		i = print_comma_and_space(lenght, cent);
		translate(num, cent);
		print_b_num_3(lenght, num, i);
		lenght -= 3;
	}
	free(cent);
}

void	print_b_num_1(int lenght, t_Number *num, char *number, int i)
{
	int		j;
	char	*cent;
	char	*magnitude;

	j = -1;
	while ((lenght - 1) % 3 != 0)
		lenght--;
	magnitude = malloc(lenght);
	magnitude[0] = '1';
	while (++i < lenght)
		magnitude[i] = '0';
	lenght = ft_strlen(number) % 3;
	if (!lenght)
		lenght = 3;
	cent = malloc(sizeof(char) * lenght);
	i = -1;
	while (++i < lenght)
		cent[i] = number[++j];
	translate(num, cent);
	write(1, " ", 1);
	ft_putstr(ft_strcmp(num, magnitude));
	print_b_num_2(lenght, num, number, j);
	free(magnitude);
	free(cent);
}

void	translate(t_Number *num, char *number)
{
	int	lenght;
	int	n;

	lenght = ft_strlen(number);
	if (number[0] == '-')
	{
		write(1, "error", 5);
		return ;
	}
	if (lenght < 3)
	{
		n = ft_atoi(number);
		if (n >= 0 && n <= 19)
			ft_putstr(ft_strcmp(num, number));
		else if (n >= 20 && n <= 99 && n % 10 == 0)
			ft_putstr(ft_strcmp(num, number));
		else
			number_magnitude(num, number, 0);
	}
	else if (lenght == 3)
		number_magnitude(num, number, 0);
	else
		print_b_num_1(lenght, num, number, 0);
}
