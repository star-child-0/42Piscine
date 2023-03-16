/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:54:28 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/01 21:54:30 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_row_length(char *str, int i)
{
	while (str[++i] != '\n')
		i++;
	return (i);
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

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	check_map_area(char *str, char *app)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == app[0] || str[i] == app[1]
				|| str[i] == app[2] || str[i] == app[3]))
			return (0);
		i++;
	}
	return (1);
}
