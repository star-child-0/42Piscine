/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:03:51 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;
	int	n;

	i = power;
	n = nb;
	if (i > 1)
	{
		return (nb * ft_recursive_power(nb, (i - 1)));
	}
	if (i == 0)
		return (1);
	if (i < 0)
		return (0);
	return (n);
}
