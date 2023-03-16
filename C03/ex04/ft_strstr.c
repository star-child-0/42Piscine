/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:14:12 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/21 20:24:13 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && to_find[0] != '\0')
	{
		while (str[i + k] == to_find[k] && str[i + k] != '\0')
			k++;
		if (to_find[k] == '\0')
			return (str + i);
		i++;
		k = 0;
	}
	return ('\0');
}
