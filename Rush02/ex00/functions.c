/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:05:18 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/31 15:05:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '.' || str[i] == ',')
			return (-1);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_trim2(char *buffer, char *str, int i)
{
	int		j;
	int		space_check;

	space_check = 0;
	j = 0;
	while (str[++i] != '\0')
	{
		while (str[++i - 1] == ' ' && str[i] == ' ')
			space_check = 1;
		while (str[++i] >= 33 && str[i] <= 126)
		{
			if (space_check == 1)
			{
				buffer[++j] = ' ';
				space_check = 0;
			}
			buffer[++j] = str[i];
		}
	}
	buffer[j] = '\0';
	return (buffer);
}

char	*ft_trim(char *str)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc(ft_strlen(str)- 1);
	i = 0;
	while (str[i] == ' ')
		i++;
	return (ft_trim2(buffer, str, i));
}
