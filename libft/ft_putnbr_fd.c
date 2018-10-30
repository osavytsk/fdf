/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:37:59 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int c;

	c = 1;
	if (nb < 0)
		c = -1;
	if (nb / 10 == 0)
	{
		if (nb < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd((char)((int)'0' + nb % 10 * c), fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((char)((int)'0' + nb % 10 * c), fd);
	}
}
