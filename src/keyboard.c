/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:53 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_x(void *par)
{
	(void)par;
	exit(1);
	return (0);
}

int	rotate(int keycode, t_apr *param)
{
	t_apr	*info;

	info = param;
	if (keycode == 88)
		info->param->rotate_y += M_PI / 180;
	else if (keycode == 86)
		info->param->rotate_y -= M_PI / 180;
	else if (keycode == 84)
		info->param->rotate_x += M_PI / 180;
	else if (keycode == 91)
		info->param->rotate_x -= M_PI / 180;
	return (0);
}

int	shift(int keycode, t_apr *param)
{
	t_apr	*info;

	info = param;
	if (keycode == 125 && info->param->shift_y < 2 * info->fmap->win_h)
		info->param->shift_y += info->param->scale + 1;
	else if (keycode == 126 && info->param->shift_y > -2 * info->fmap->win_h)
		info->param->shift_y -= info->param->scale + 1;
	else if (keycode == 124 && info->param->shift_y < 2 * info->fmap->win_w)
		info->param->shift_x += info->param->scale + 1;
	else if (keycode == 123 && info->param->shift_y > -2 * info->fmap->win_w)
		info->param->shift_x -= info->param->scale + 1;
	return (0);
}

int	scale(int keycode, t_apr *info)
{
	int w;
	int h;
	int scale;

	scale = info->param->scale;
	w = info->fmap->w;
	h = info->fmap->h;
	if (keycode == 18)
	{
		if (scale * (w > h ? w : h) + 1500 < 2147483647)
			info->param->scale++;
		return (0);
	}
	else
	{
		if (scale > 1)
			info->param->scale--;
		return (0);
	}
}

int	control(int keycode, void *param)
{
	t_apr	*info;

	info = param;
	if (keycode == 53)
		exit_x(info);
	else if (keycode == 88 || keycode == 86 || keycode == 84 || keycode == 91)
		rotate(keycode, info);
	else if (keycode >= 123 && keycode <= 126)
		shift(keycode, info);
	else if (keycode == 18 || keycode == 19)
		scale(keycode, info);
	else if (keycode == 49)
	{
		info->param->scale = info->param->basic_scale;
		info->param->rotate_x = 0;
		info->param->rotate_y = 0;
		info->param->shift_x = info->fmap->win_w / 2;
		info->param->shift_y = info->fmap->win_h / 2;
	}
	else
		return (0);
	mlx_clear_window(info->win->mlx, info->win->win);
	draw_map((s_convert_map(info->fmap, info->param, info->cmap)),
	info->win, info->fmap);
	return (0);
}
