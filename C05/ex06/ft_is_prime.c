/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:30:43 by anvannin          #+#    #+#             */
/*   Updated: 2022/08/02 20:32:00 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb > 1)
	{
		i = 2;
		while (i < nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int main ()
{
	#include<stdio.h>
	printf("%d", ft_is_prime(2147483647));
		printf("%d", ft_is_prime(2147483647));
			printf("%d", ft_is_prime(2147483647));
				printf("%d", ft_is_prime(2147483647));
					printf("%d", ft_is_prime(2147483647));
							printf("%d", ft_is_prime(2147483647));
								printf("%d", ft_is_prime(2147483647));
						printf("%d", ft_is_prime(2147483647));
									
}
