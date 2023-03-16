/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:40 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 11:09:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_row_length(char *str, int i);
int		check_map_area(char *str, char *app);
void	str_to_matrix(char *str, int cols, int rows);

int	check_map_header(char *str, int i)
{	
	char	app[4];

	while (str[i] != '\n')
		i++;
	i--;
	if (str[i] != str[i - 1] && str[i] != str[i - 2]
		&& str[i - 1] != str[i - 2] && i > 2)
	{
		app[3] = '\n';
		app[0] = str[i - 2];
		app[1] = str[i - 1];
		app[2] = str[i];
		if (check_map_area(str + 2, app))
			return (1);
	}
	return (0);
}

int	check_rows_lenght(char *str, int rowl, int rows)
{
	int	i;
	int	cycle;

	i = 0;
	cycle = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (i - cycle) % rowl == 0)
			cycle ++;
		i++;
	}
	return (cycle - rows);
}

int	map_rows(char	*str)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			rows++;
		i++;
	}
	return (rows -1);
}

void	check_map(char *str, int i)
{
	int	flag;
	int	rowl;

	flag = 1;
	rowl = 0;
	if (ft_atoi(str) > 0 && str[0] != '0' && check_map_header(str, 0) != 0)
	{
		while (str[i] != '\n')
			i++;
		while (str[++i] != '\n')
			rowl++;
		if (check_rows_lenght(str + i + 1, rowl, map_rows(str)) == -1)
			str_to_matrix(str, map_rows(str), rowl);
		else
			flag = 0;
	}
	else
		write(1, "map error\n", 10);
	if (flag == 0)
		write(1, "map error\n", 10);
}

void	map_to_str(char *dict, int i)
{
	int		fd;
	char	c;
	char	*str;

	fd = open(dict, 'r');
	if (read(fd, &c, 1) != -1)
	{
		while (read(fd, &c, 1))
			i++;
		close(fd);
		str = (char *)malloc(i * sizeof(char));
		i = -1;
		fd = open(dict, 'r');
		while (read(fd, &c, 1))
			str[++i] = c;
		close(fd);
		check_map(str, -1);
	}
	else
		write(1, "map error\n", 10);
}
