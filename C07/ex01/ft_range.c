/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:50:24 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/03 15:50:32 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
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
		return (arr);
	}
	return (arr = NULL);
}
