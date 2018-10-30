/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	take_color(t_std p1, t_point cl, int i, int n)
{
	t_color res;

	res.space[D] = 0;
	res.space[R] = p1.color.space[R] - cl.x * i / n - (cl.x * i) % n * 2 / n;
	res.space[G] = p1.color.space[G] - cl.y * i / n - (cl.y * i) % n * 2 / n;
	res.space[B] = p1.color.space[B] - cl.z * i / n - (cl.z * i) % n * 2 / n;
	return (res.i_color);
}

void			print_line(t_std p1, t_std p2, t_window *window)
{
	int		j;
	int		i;
	t_std	dlt;
	t_std	cr_dt;
	t_point	color;

	dlt.x = p1.x - p2.x;
	dlt.y = p1.y - p2.y;
	color.x = p1.color.space[R] - p2.color.space[R];
	color.y = p1.color.space[G] - p2.color.space[G];
	color.z = p1.color.space[B] - p2.color.space[B];
	i = 1;
	j = abs(dlt.x) > abs(dlt.y) ? abs(dlt.x) : abs(dlt.y);
	mlx_pixel_put(window->mlx, window->window, p1.x, p1.y, p1.color.i_color);
	while (i <= j)
	{
		cr_dt.x = p1.x - (dlt.x * i / j + dlt.x * i % j * 2 / j);
		cr_dt.y = p1.y - (dlt.y * i / j + dlt.y * i % j * 2 / j);
		cr_dt.color.i_color = take_color(p1, color, i, j);
		i++;
		mlx_pixel_put(window->mlx, window->window, cr_dt.x, cr_dt.y,
		cr_dt.color.i_color);
	}
}

int				limt(t_std p1, t_chart *full_map)
{
	if ((full_map->window_w >= p1.x) && (full_map->window_h >= p1.y))
	{
		if (0 <= p1.x && 0 <= p1.y)
			return (1);
	}
	return (0);
}

void			print_stand(t_std **tab, t_window *window, t_chart *ftab)
{
	int j;
	int i;

	j = 0;
	i = ftab->h - 1;
	while (j < ftab->width - 1)
	{
		if (limt(tab[i][j], ftab) || limt(tab[i][j + 1], ftab))
			print_line(tab[i][j], tab[i][j + 1], window);
		j++;
	}
}

void			draw_tab(t_std **mp, t_window *wdw, t_chart *fl_mp)
{
	int i;
	int j;

	i = 0;
	while (i < fl_mp->h - 1)
	{
		j = 0;
		while (j < fl_mp->width - 1)
		{
			if (limt(mp[i][j], fl_mp) || limt(mp[i + 1][j], fl_mp))
				print_line(mp[i][j], mp[i + 1][j], wdw);
			if (limt(mp[i][j], fl_mp) || limt(mp[i][j + 1], fl_mp))
				print_line(mp[i][j], mp[i][j + 1], wdw);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < fl_mp->h - 1)
	{
		if (limt(mp[i][j], fl_mp) || limt(mp[i + 1][j], fl_mp))
			print_line(mp[i][j], mp[i + 1][j], wdw);
		i++;
	}
	print_stand(mp, wdw, fl_mp);
}
