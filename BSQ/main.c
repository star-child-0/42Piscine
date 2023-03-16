/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:46:52 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 11:10:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	map_to_str(char *dict, int i);

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		while (++i < argc)
			map_to_str(argv[i], 0);
	}
	return (0);
}
