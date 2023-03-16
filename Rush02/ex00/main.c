/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:39 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/30 17:09:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_Number.h"

int	file_to_str(char *dict, char *number, int i);

int	main(int argc, char *argv[])
{	
	if (argc == 2)
	{
		if (!file_to_str("numbers.dict", argv[1], 0))
			return (0);
	}
	else if (argc == 3)
	{
		if (!file_to_str(argv[1], argv[2], 0))
			return (0);
	}
	write(1, "\n", 1);
	return (0);
}
