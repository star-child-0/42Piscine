/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:07:15 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 17:07:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	str_to_matrix(char *str, int cols, int rows)
{
	int		x;
	int		y;
	int		i;
	char	**matrix;

	matrix = malloc(cols * sizeof(char *));
	i = 0;
	while (str[i] != '\n')
		i++;
	x = 0;
	while (x < cols)
	{
		y = 0;
		while (y < rows)
		{
			if (str[i] != '\n')
			{
				matrix[y] = malloc(rows * sizeof(char));
				matrix[y][x] = str[i];
				y++;
			}
			i++;
		}
		x++;
	}
}
