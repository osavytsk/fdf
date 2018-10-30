/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:38:01 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int c;

	c = 1;
	if (nb < 0)
		c = -1;
	if (nb / 10 == 0)
	{
		if (nb < 0)
			ft_putchar('-');
		ft_putchar((char)((int)'0' + nb % 10 * c));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((char)((int)'0' + nb % 10 * c));
	}
}
