/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:33:01 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_hex(char **line)
{
	int				i;
	unsigned int	res;

	res = 0;
	i = 5;
	while (i >= 0)
	{
		if (**line >= '0' && **line <= '9')
			res += (**line - '0') * f_pow(16, i);
		else if (**line >= 'A' && **line <= 'F')
			res += (**line - 'A' + 10) * f_pow(16, i);
		else if (**line >= 'a' && **line <= 'f')
			res += (**line - 'a' + 10) * f_pow(16, i);
		else if ((**line >= ' ' || **line <= '\t') && i < 5)
			return (res);
		else
			return (0x1000000);
		(*line)++;
		i--;
	}
	if (**line == ' ' || **line == '\t' || **line == '\0')
		return (res);
	else
		return (0x1000000);
}

int				cancer_atoi(char **str)
{
	int	sum;
	int	d;

	sum = 0;
	d = 1;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str == '-')
	{
		d = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		sum = sum * 10 + (int)((**str - '0') * d);
		if (sum >= 23169)
			return (1 << 15);
		(*str)++;
	}
	return (sum);
}

int				parse_color(char **line, t_map *fmap, int i, int k)
{
	if (**line == ',')
	{
		if (*(*line + 1) == '0' && *(*line + 2) == 'x')
		{
			(*line) += 3;
			if ((fmap->map[i][k].color.i_clr = get_hex(line)) == 0x1000000)
				return (0);
			return (1);
		}
	}
	else if (**line == ' ' || **line == '\t' || **line == '\0')
	{
		if (fmap->map[i][k].z < -10)
			fmap->map[i][k].color.i_clr = 0x0000FF;
		else if (fmap->map[i][k].z < -3)
			fmap->map[i][k].color.i_clr = 0x00FFFF;
		else if (fmap->map[i][k].z < 3)
			fmap->map[i][k].color.i_clr = 0x00FF00;
		else if (fmap->map[i][k].z < 10)
			fmap->map[i][k].color.i_clr = 0xFFFF00;
		else if (fmap->map[i][k].z >= 10)
			fmap->map[i][k].color.i_clr = 0xFF0000;
		return (1);
	}
	return (0);
}

int				parse_line(char *line, t_map *fmap, unsigned int i)
{
	unsigned int	k;

	k = 0;
	fmap->map[i] = (t_dot *)malloc(sizeof(t_dot) * fmap->w);
	while (*line)
	{
		if ((fmap->map[i][k].z = cancer_atoi(&line)) == (1 << 15))
			return (0);
		fmap->map[i][k].x = k - fmap->w / 2;
		fmap->map[i][k].y = i - fmap->h / 2;
		if (!parse_color(&line, fmap, i, k))
			return (0);
		while (*line == ' ' || *line == '\t')
			line++;
		if (line == '\0')
			return (1);
		++k;
	}
	return (1);
}

int				dirty_work(int fd, char *line, t_map *fmap)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!parse_line(line, fmap, i))
		{
			self_destruction(fmap, i);
			free(line);
			return (0);
		}
		free(line);
		i++;
	}
	free(line);
	fmap->h = i;
	return (1);
}
