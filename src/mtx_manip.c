/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:58 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		matrix_setup(t_rotate *mat, t_prms *fp)
{
	mat->sinus_x = fp->zoom * sin(fp->rot_x);
	mat->rot_asis = sin(fp->rot_x);
	mat->sinus_y = fp->zoom * sin(fp->rot_y);
	mat->cosinus_x = fp->zoom * cos(fp->rot_x);
	mat->cosinus_y = fp->zoom * cos(fp->rot_y);
}

void		mlt_mtx(t_point *full_map, t_prms *fp, t_std *c_mp, t_rotate mx)
{
	int i;
	int i1;

	i = -full_map->x * mx.sinus_y;
	i += full_map->z * mx.cosinus_y;
	c_mp->x = full_map->x * mx.cosinus_y;
	c_mp->x += full_map->z * mx.sinus_y;
	i1 = -full_map->y * mx.sinus_x;
	i1 += i * mx.cosinus_x;
	c_mp->y = full_map->y * mx.cosinus_x;
	c_mp->y += i * mx.rot_asis;
	c_mp->y += fp->shf_y;
	c_mp->x += fp->shf_x;
	c_mp->color = full_map->color;
}

t_std		**map_conv(t_chart *fl_mp, t_prms *f_cond, t_std **cr_mp)
{
	t_rotate	mx;
	int			i;
	int			j;

	matrix_setup(&mx, f_cond);
	i = 0;
	while (i < fl_mp->h)
	{
		j = 0;
		while (j < fl_mp->width)
		{
			mlt_mtx(&(fl_mp->mappa[i][j]), f_cond, &(cr_mp[i][j]), mx);
			++j;
		}
		++i;
	}
	return (cr_mp);
}

t_std		**conv_map(t_chart *full_map, t_prms *f_param)
{
	t_std		**c_map;
	t_rotate	mtx;
	int			i;
	int			k;

	i = 0;
	matrix_setup(&mtx, f_param);
	c_map = (t_std **)malloc(sizeof(t_std *) * full_map->h);
	while (i < full_map->h)
	{
		k = 0;
		c_map[i] = (t_std *)malloc(sizeof(t_std) * full_map->width);
		while (k < full_map->width)
		{
			mlt_mtx(&(full_map->mappa[i][k]), f_param, &(c_map[i][k]), mtx);
			++k;
		}
		++i;
	}
	return (c_map);
}
