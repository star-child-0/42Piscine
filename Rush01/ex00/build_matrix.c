/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:12:50 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/24 14:12:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	one_four_series(int i, char mat[4][4], int k);
void	incomplete_series(char mat[4][4]);

void	print_matrix(char mat[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			write(1, &mat[x][y], 1);
			if (y != 3)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

void	matrix_corners_one(char mat[4][4], char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '4')
		{
			if (i >= 0 && i <= 7)
				mat[0][k] = '1';
			if (i >= 8 && i <= 15)
				mat[3][k - 4] = '1';
			if (i >= 16 && i <= 23)
				mat[k - 8][0] = '1';
			if (i >= 24 && i <= 31)
				mat[k - 12][3] = '1';
			one_four_series(i, mat, k);
		}
		k++;
		i += 2;
	}
}

void	matrix_corners_four(char mat[4][4], char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
		{
			if (i >= 0 && i <= 7)
				mat[0][k] = '4';
			if (i >= 8 && i <= 15)
				mat[3][k - 4] = '4';
			if (i >= 16 && i <= 23)
				mat[k - 8][0] = '4';
			if (i >= 24 && i <= 31)
				mat[k - 12][3] = '4';
		}
		k++;
		i += 2;
	}
	matrix_corners_one(mat, str);
}

void	build_matrix(char *str)
{
	char	mat[4][4];
	int		x;
	int		y;

	x = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			mat[x][y] = '0';
			y++;
		}
		x++;
	}
	matrix_corners_four(mat, str);
	print_matrix(mat);
}
