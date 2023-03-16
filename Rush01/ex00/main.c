/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:06:43 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/23 19:31:02 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	build_matrix(char *str);

int		check_string_format(char *str);

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "You haven't inserted any number silly", 37);
	else if (argc == 2)
	{
		if (check_string_format(argv[1]) == 1)
			build_matrix(argv[1]);
		else
			write(1, "The inserted string is incorrectly formatted", 44);
	}
	else
		write(1, "Please insert all the numbers within quotation marks", 52);
	return (0);
}
