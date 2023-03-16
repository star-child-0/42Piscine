/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:06:29 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/16 12:07:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	riga;
	int	col;

	col = 1;
	while (col <= y && x > 0)
	{
		riga = 1;
		while (riga <= x)
		{
			if ((col == 1 && riga == 1)
				|| (col == y && riga == x && col != 1 && riga != 1))
				ft_putchar('/');
			else if ((col == 1 && riga == x) || (riga == 1 && col == y))
				ft_putchar('\\');
			else if (col == 1 || col == y || riga == 1 || riga == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			riga++;
		}
		ft_putchar('\n');
		col++;
	}
}
