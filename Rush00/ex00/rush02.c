/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:19:10 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/16 22:38:12 by anvannin         ###   ########.fr       */
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
			if ((riga == 1 || riga == x) && col == 1)
				ft_putchar('A');
			else if ((riga == 1 || riga == x) && col == y)
				ft_putchar('C');
			else if (col == 1 || col == y || riga == 1 || riga == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			riga++;
		}
		ft_putchar('\n');
		col++;
	}
}
