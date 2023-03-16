/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:16:39 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/26 18:16:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nbr = -nbr;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (nbr);
}

int	calculate_nbr_base(char *nbr, char *base, int size)
{
	int	n;

	if (nbr >= size)
		calculate_nbr_base(((nbr / size) - 48), base, size);
	n = base[nbr % size] -48 ;
	return (n);
}

char	*ft_putnbr_base(char *str, char *base, int i)
{
	int	k;
	int	r;

	while (base[++i] != '\0')
	{	
		if (base[i] == '+' || base[i] == '-' || base[1] == '\0')
			break ;
		k = i + 1;
		while (base[k] != '\0')
		{
			if (base[i] == base[k])
			{
				r = 0;
				break ;
			}
			else
				r = 1;
			k++;
		}
	}
	if (r == 1)
		calculate_nbr_base(str, base, i);
	else
		return ('0');
}

int	ft_atoi_base(char *str, char *base)
{
	char	*n;
	int		nb;

	n = ft_putnbr_base(str, base, -1);
	nb = ft_atoi(str);
	return (nb);
}
