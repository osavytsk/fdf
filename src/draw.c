/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(t_cdt d1, t_dot color, int i, int n)
{
	t_clr res;

	res.spc[D] = 0;
	res.spc[R] = d1.color.spc[R] - color.x * i / n - (color.x * i) % n * 2 / n;
	res.spc[G] = d1.color.spc[G] - color.y * i / n - (color.y * i) % n * 2 / n;
	res.spc[B] = d1.color.spc[B] - color.z * i / n - (color.z * i) % n * 2 / n;
	return (res.i_clr);
}

void			draw_line(t_cdt d1, t_cdt d2, t_win *win)
{
	int		n;
	int		i;
	t_cdt	dlt;
	t_cdt	curr_dot;
	t_dot	color;

	dlt.x = d1.x - d2.x;
	dlt.y = d1.y - d2.y;
	color.x = d1.color.spc[R] - d2.color.spc[R];
	color.y = d1.color.spc[G] - d2.color.spc[G];
	color.z = d1.color.spc[B] - d2.color.spc[B];
	i = 1;
	n = abs(dlt.x) > abs(dlt.y) ? abs(dlt.x) : abs(dlt.y);
	mlx_pixel_put(win->mlx, win->win, d1.x, d1.y, d1.color.i_clr);
	while (i <= n)
	{
		curr_dot.x = d1.x - (dlt.x * i / n + dlt.x * i % n * 2 / n);
		curr_dot.y = d1.y - (dlt.y * i / n + dlt.y * i % n * 2 / n);
		curr_dot.color.i_clr = get_color(d1, color, i, n);
		i++;
		mlx_pixel_put(win->mlx, win->win, curr_dot.x, curr_dot.y,
		curr_dot.color.i_clr);
	}
}

int				ft_limit(t_cdt d1, t_map *fmap)
{
	if ((fmap->win_w >= d1.x) && (fmap->win_h >= d1.y))
	{
		if (0 <= d1.x && 0 <= d1.y)
			return (1);
	}
	return (0);
}

void			draw_stand(t_cdt **map, t_win *win, t_map *fmap)
{
	int k;
	int i;

	k = 0;
	i = fmap->h - 1;
	while (k < fmap->w - 1)
	{
		if (ft_limit(map[i][k], fmap) || ft_limit(map[i][k + 1], fmap))
			draw_line(map[i][k], map[i][k + 1], win);
		k++;
	}
}

void			draw_map(t_cdt **map, t_win *win, t_map *fmap)
{
	int i;
	int k;

	i = 0;
	while (i < fmap->h - 1)
	{
		k = 0;
		while (k < fmap->w - 1)
		{
			if (ft_limit(map[i][k], fmap) || ft_limit(map[i + 1][k], fmap))
				draw_line(map[i][k], map[i + 1][k], win);
			if (ft_limit(map[i][k], fmap) || ft_limit(map[i][k + 1], fmap))
				draw_line(map[i][k], map[i][k + 1], win);
			k++;
		}
		i++;
	}
	i = 0;
	while (i < fmap->h - 1)
	{
		if (ft_limit(map[i][k], fmap) || ft_limit(map[i + 1][k], fmap))
			draw_line(map[i][k], map[i + 1][k], win);
		i++;
	}
	draw_stand(map, win, fmap);
}
