/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:33:04 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	float_power(int n, int p)
{
	int rt;

	rt = 1;
	while (p)
	{
		rt = rt * n;
		p--;
	}
	return (rt);
}

int	solo_destruct(t_chart *full_map, int i)
{
	while (i >= 0)
	{
		free(full_map->mappa[i]);
		i--;
	}
	free(full_map->mappa);
	return (0);
}

int	count_wrd(char *s)
{
	int cl;
	int rw;

	rw = 0;
	cl = 0;
	if (s[0] != ' ' && s[0] != '\t')
	{
		cl++;
		rw++;
	}
	while (s[rw] != '\0')
	{
		if ((s[rw] != ' ' && s[rw] != '\t') && (s[rw - 1] == ' ' ||
		s[rw - 1] == '\t'))
			cl++;
		rw++;
	}
	return (cl);
}
