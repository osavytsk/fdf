/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:33:01 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	take_hex(char **s)
{
	int				i;
	unsigned int	ret;

	ret = 0;
	i = 5;
	while (i >= 0)
	{
		if (**s >= '0' && **s <= '9')
			ret += (**s - '0') * float_power(16, i);
		else if (**s >= 'A' && **s <= 'F')
			ret += (**s - 'A' + 10) * float_power(16, i);
		else if (**s >= 'a' && **s <= 'f')
			ret += (**s - 'a' + 10) * float_power(16, i);
		else if ((**s >= ' ' || **s <= '\t') && i < 5)
			return (ret);
		else
			return (0x1000000);
		(*s)++;
		i--;
	}
	if (**s == ' ' || **s == '\t' || **s == '\0')
		return (ret);
	else
		return (0x1000000);
}

int				best_atoi_ever(char **s)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (**s == ' ' || **s == '\t')
		(*s)++;
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		res = res * 10 + (int)((**s - '0') * sign);
		if (res >= 23169)
			return (1 << 15);
		(*s)++;
	}
	return (res);
}

int				parse_clr(char **s, t_chart *ful_mp, int i, int j)
{
	if (**s == ',')
	{
		if (*(*s + 1) == '0' && *(*s + 2) == 'x')
		{
			(*s) += 3;
			if ((ful_mp->mappa[i][j].color.i_color = take_hex(s)) == 0x1000000)
				return (0);
			return (1);
		}
	}
	else if (**s == ' ' || **s == '\t' || **s == '\0')
	{
		if (ful_mp->mappa[i][j].z < -10)
			ful_mp->mappa[i][j].color.i_color = 0x0000FF;
		else if (ful_mp->mappa[i][j].z < -3)
			ful_mp->mappa[i][j].color.i_color = 0x00FFFF;
		else if (ful_mp->mappa[i][j].z < 3)
			ful_mp->mappa[i][j].color.i_color = 0x00FF00;
		else if (ful_mp->mappa[i][j].z < 10)
			ful_mp->mappa[i][j].color.i_color = 0xFFFF00;
		else if (ful_mp->mappa[i][j].z >= 10)
			ful_mp->mappa[i][j].color.i_color = 0xFF0000;
		return (1);
	}
	return (0);
}

int				parse_ln(char *s, t_chart *ful_mp, unsigned int i)
{
	unsigned int	j;

	j = 0;
	ful_mp->mappa[i] = (t_point *)malloc(sizeof(t_point) * ful_mp->width);
	while (*s)
	{
		if ((ful_mp->mappa[i][j].z = best_atoi_ever(&s)) == (1 << 15))
			return (0);
		ful_mp->mappa[i][j].x = j - ful_mp->width / 2;
		ful_mp->mappa[i][j].y = i - ful_mp->h / 2;
		if (!parse_clr(&s, ful_mp, i, j))
			return (0);
		while (*s == ' ' || *s == '\t')
			s++;
		if (s == '\0')
			return (1);
		++j;
	}
	return (1);
}

int				dirt_job(int fd, char *l, t_chart *full_map)
{
	int i;

	i = 0;
	while (get_next_line(fd, &l) == 1)
	{
		if (!parse_ln(l, full_map, i))
		{
			solo_destruct(full_map, i);
			free(l);
			return (0);
		}
		free(l);
		i++;
	}
	free(l);
	full_map->h = i;
	return (1);
}
