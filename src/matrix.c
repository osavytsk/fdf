/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:58 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_matrix(t_rot *mtx, t_par *fpar)
{
	mtx->sinx = fpar->scale * sin(fpar->rotate_x);
	mtx->asis = sin(fpar->rotate_x);
	mtx->siny = fpar->scale * sin(fpar->rotate_y);
	mtx->cosx = fpar->scale * cos(fpar->rotate_x);
	mtx->cosy = fpar->scale * cos(fpar->rotate_y);
}

void	mult_matrix(t_dot *fmap, t_par *fpar, t_cdt *c_map, t_rot mtx)
{
	int z;
	int z1;

	z = -fmap->x * mtx.siny;
	z += fmap->z * mtx.cosy;
	c_map->x = fmap->x * mtx.cosy;
	c_map->x += fmap->z * mtx.siny;
	z1 = -fmap->y * mtx.sinx;
	z1 += z * mtx.cosx;
	c_map->y = fmap->y * mtx.cosx;
	c_map->y += z * mtx.asis;
	c_map->y += fpar->shift_y;
	c_map->x += fpar->shift_x;
	c_map->color = fmap->color;
}

t_cdt	**s_convert_map(t_map *fmap, t_par *fpar, t_cdt **c_map)
{
	t_rot	mtx;
	int		i;
	int		k;

	init_matrix(&mtx, fpar);
	i = 0;
	while (i < fmap->h)
	{
		k = 0;
		while (k < fmap->w)
		{
			mult_matrix(&(fmap->map[i][k]), fpar, &(c_map[i][k]), mtx);
			++k;
		}
		++i;
	}
	return (c_map);
}

t_cdt	**convert_map(t_map *fmap, t_par *fpar)
{
	t_cdt	**c_map;
	t_rot	mtx;
	int		i;
	int		k;

	i = 0;
	init_matrix(&mtx, fpar);
	c_map = (t_cdt **)malloc(sizeof(t_cdt *) * fmap->h);
	while (i < fmap->h)
	{
		k = 0;
		c_map[i] = (t_cdt *)malloc(sizeof(t_cdt) * fmap->w);
		while (k < fmap->w)
		{
			mult_matrix(&(fmap->map[i][k]), fpar, &(c_map[i][k]), mtx);
			++k;
		}
		++i;
	}
	return (c_map);
}
