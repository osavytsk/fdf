/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:34:03 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(int nb, int n, char *str)
{
	int c;

	c = 1;
	if (nb < 0)
		c = -1;
	if (nb / 10 == 0)
	{
		if (nb < 0)
			str[n - 1] = '-';
		str[n] = (char)((int)'0' + nb % 10 * c);
	}
	else
	{
		putnbr(nb / 10, n - 1, str);
		str[n] = (char)((int)'0' + nb % 10 * c);
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		d;
	int		n1;

	n1 = n;
	d = 1;
	while (n1 / 10 != 0)
	{
		d++;
		n1 = n1 / 10;
	}
	if (n < 0)
		d++;
	str = ft_strnew((size_t)d);
	if (!str)
		return (NULL);
	putnbr(n, d - 1, str);
	return (str);
}
