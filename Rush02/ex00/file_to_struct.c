/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:10:40 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/30 17:10:57 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_Number.h"

void	translate(t_Number *num, char *number);

int	validate_file(char *str, int i)
{
	while (str[i] != ' ' && str[i] != ':')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	while (str[i] == ' ' && str[i] != ':' && str[i] != '\0')
		i++;
	if (str[i - 1] == ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

t_Number	build_struct(char *st)
{
	int			i;
	int			j;
	int			k;
	t_Number	num;

	i = 0;
	while (st[i] != ':' && st[i] != ' ')
		i++;
	num.nb = (char *)malloc(i * sizeof(char));
	i = -1;
	while (st[++i] != ':' && st[i] != ' ')
		num.nb[i] = st[i];
	while (st[i] == ':' || st[i] == ' ')
		i++;
	j = i - 1;
	while (st[i] != '\n')
		i++;
	num.word = (char *)malloc((i - j) * sizeof(char));
	k = -1;
	while (++j < i)
		num.word[++k] = st[j];
	return (num);
}

void	split_row(char *str, char *number)
{
	int			word;
	int			i;
	t_Number	*num;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			word++;
		i++;
	}
	num = (t_Number *)malloc(word * sizeof(t_Number));
	i = 1;
	num[0] = build_struct(str);
	while (*(++str) != '\0' && *(str + 1) != '\0')
	{
		if (*str == '\n' && (*(str + 1) != '\n' || *(str + 1) == '\0'))
		{
			num[i] = build_struct(++str);
			word++;
			i++;
		}
	}
	translate(num, number);
}

int	file_to_str_validate(char *str)
{
	while (*str != '\0')
	{
		if (!validate_file(str, 0))
		{
			write(1, "Dict error\n", 11);
			return (0);
		}
		while (*str != '\n')
			str++;
		str++;
	}
	return (1);
}

int	file_to_str(char *dict, char *number, int i)
{
	int		fd;
	char	*pointer;
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
		pointer = str;
		if (!file_to_str_validate(str))
			return (0);
		split_row(pointer, number);
	}
	else
		write(1, "Dict Error", 10);
	return (1);
}
