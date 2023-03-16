/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:21:30 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/03 17:21:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**ft_split2(char **mat, int word_count, char *str)
{
	int	s;
	int	w;
	int	i;

	i = 0;
	while (i <= word_count)
	{	
		w = i + 1;
		s = 0;
		mat[i] = (char *)malloc(5 * sizeof(char));
		while (str[s] != '\0' && (str[s + 1] != ' '
				|| str[s + 1] != '\t' || str[s + 1] != '\n'))
		{
			mat[i][w] = str[s];
			s++;
			w++;
		}
		if (str[s] != '\0')
			str[s] = '\0';
		i++;
	}
	return (mat);
}

char	**ft_split(char *str)
{
	int		i;
	int		s;
	int		w;
	int		word_count;
	char	**mat;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n')
			&& str[i + 1] != '\0')
		{
			word_count++;
		}
		i++;
	}
	mat = (char **)malloc(word_count * sizeof(char *));
	return (ft_split2(mat, word_count, str));
}
