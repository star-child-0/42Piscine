/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:04:40 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 20:08:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int i)
{
	if (i < 0)
		return (-1);
	if (i < 2)
		return (i);
	return (ft_fibonacci(i - 2) + ft_fibonacci(i - 1));
}
