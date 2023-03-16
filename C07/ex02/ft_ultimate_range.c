/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:10:57 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/03 17:10:59 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;

	if (min < max)
	{
		arr = malloc((max - min) * sizeof(int));
		while (min < max)
		{
			arr[min] = min;
			min++;
		}
		*range = arr;
		return (max - min);
	}
	range = NULL;
	return (-1);
}
