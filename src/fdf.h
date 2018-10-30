/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:49 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define DEFAULT_SCALE 30
# define B 0
# define G 1
# define R 2
# define D 3

typedef union		u_clr
{
	unsigned int	i_clr;
	unsigned char	spc[4];
}					t_clr;

typedef struct		s_dot
{
	int		x;
	int		y;
	int		z;
	t_clr	color;
}					t_dot;

typedef struct		s_cdt
{
	int		x;
	int		y;
	t_clr	color;
}					t_cdt;

typedef struct		s_map
{
	int		win_w;
	int		win_h;
	int		w;
	int		h;
	t_dot	**map;
}					t_map;

typedef struct		s_win
{
	void	*mlx;
	void	*win;
}					t_win;

typedef struct		s_par
{
	int		basic_scale;
	int		scale;
	int		shift_x;
	int		shift_y;
	float	rotate_x;
	float	rotate_y;
}					t_par;

typedef struct		s_apr
{
	t_map	*fmap;
	t_par	*param;
	t_win	*win;
	t_cdt	**cmap;
}					t_apr;

typedef struct		s_rot
{
	float	sinx;
	float	siny;
	float	cosx;
	float	cosy;
	float	asis;
}					t_rot;

void				draw_map(t_cdt **map, t_win *win, t_map *fmap);
t_cdt				**s_convert_map(t_map *fmap, t_par *fpar, t_cdt **c_map);
int					cancer_atoi(char **str);
t_cdt				**convert_map(t_map *fmap, t_par *fpar);
int					init_map(t_map *fmap, char **argv);
int					self_destruction(t_map *fmap, int i);
int					exit_x(void *par);
int					control(int keycode, void *param);
int					f_pow(int num, int p);
int					dirty_work(int fd, char *line, t_map *fmap);

#endif
