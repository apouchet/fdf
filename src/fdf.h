/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:13:59 by apouchet          #+#    #+#             */
/*   Updated: 2017/01/28 16:14:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"

# define FENETRE 1200

typedef struct	s_picture
{
	int			bpp;
	int			s_l;
	int			endian;
}				t_picture;

typedef struct	s_angle
{
	float		anglex;
	float		angley;
	float		anglez;
}				t_angle;

typedef struct	s_val
{
	int			x;
	int			y;
	int			len;
	int			nb;
	void		*p_image;
	int			mid;
	int			fd;
	void		**mlx;
	float		***tab;
	int			coef;
	int			vol;
	float		rotp;
	float		roth;
	float		rotv;
	char		*image;
	int			zmax;
	int			zmin;
	int			zdif;
	int			ligne;
	float		dx;
	float		dy;
	float		fx;
	float		fy;
	float		zcolor;
	int			r;
	int			g;
	int			b;
	int			inv;
	int			col;
	int			key[269];
}				t_val;

int				main(int argc, char **argv);

int				lenligne(char **tab);

int				ft_key(t_val *val);

void			ft_exit(t_val *val, int mode);

void			ft_trace_ligne(t_val *val);

int				ft_affich(t_val *val);

void			ft_init(t_val *val);

int				ft_key_on(int keycode, t_val *val);

int				ft_key_off(int keycode, t_val *val);

void			ft_image(t_val *val, int x, int y, int color);

void			haut_gauche(t_val *val);

void			haut_droite(t_val *val);

void			bas_gauche(t_val *val);

void			bas_droite(t_val *val);

void			rotation(t_val *val, t_angle b, int x, int y);

void			ft_rot(t_val *val);

void			ft_diag(int x, int y, t_val *val);

void			ft_option_ligne(int x, int y, int mod, t_val *val);

#endif
