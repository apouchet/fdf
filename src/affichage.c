/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:46:43 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/09 17:46:51 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_option_ligne(int x, int y, int mod, t_val *val)
{
	val->dx = (int)val->tab[y][x][0] + val->mid;
	val->dy = (int)val->tab[y][x][1] + val->mid;
	if (mod == 1)
	{
		val->fx = (int)val->tab[y][x + 1][0] + val->mid;
		val->fy = (int)val->tab[y][x + 1][1] + val->mid;
	}
	else if (mod == 2)
	{
		val->fx = (int)val->tab[y - 1][x + 1][0] + val->mid;
		val->fy = (int)val->tab[y - 1][x + 1][1] + val->mid;
	}
	else if (mod == 3)
	{
		val->fx = (int)val->tab[y + 1][x][0] + val->mid;
		val->fy = (int)val->tab[y + 1][x][1] + val->mid;
	}
	ft_trace_ligne(val);
}

void	ft_ligne_mod(int x, int y, t_val *val)
{
	val->zcolor = val->tab[y][x][3];
	if (val->tab[y][x + 1][3] != -10000 && val->tab[y][x + 1][0] < val->mid &&
		val->tab[y][x + 1][1] < val->mid && val->tab[y][x + 1][0] > -val->mid &&
		val->tab[y][x + 1][1] > -val->mid)
	{
		if (val->zcolor < val->tab[y][x + 1][3])
			val->zcolor = val->tab[y][x + 1][3];
		ft_option_ligne(x, y, 1, val);
	}
	val->zcolor = val->tab[y][x][3];
	ft_diag(x, y, val);
	val->zcolor = val->tab[y][x][3];
	if (y + 1 < val->nb - 1 &&
		val->tab[y + 1][x][1] < val->mid && val->tab[y + 1][x][0] < val->mid &&
		val->tab[y + 1][x][1] > -val->mid && val->tab[y + 1][x][0] > -val->mid)
	{
		if (val->zcolor < val->tab[y + 1][x][3])
			val->zcolor = val->tab[y + 1][x][3];
		ft_option_ligne(x, y, 3, val);
	}
}

void	relier(t_val val)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < val.nb - 1)
	{
		while (val.tab[y][x][3] != -10000)
		{
			if (val.tab[y][x][0] > -val.mid && val.tab[y][x][0] < val.mid &&
				val.tab[y][x][1] > -val.mid && val.tab[y][x][1] < val.mid)
				ft_ligne_mod(x, y, &val);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_point(t_val *val)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < val->nb - 1)
	{
		while ((int)val->tab[y][x][3] != -10000)
		{
			if (val->tab[y][x][0] > -val->mid && val->tab[y][x][0] < val->mid &&
				val->tab[y][x][1] > -val->mid && val->tab[y][x][1] < val->mid)
				ft_image(val, val->tab[y][x][0] + val->mid, val->tab[y][x][1] +
					val->mid, val->tab[y][x][3]);
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_affich(t_val *val)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= FENETRE)
	{
		while (x <= FENETRE)
		{
			val->image[4 * FENETRE * y + 4 * x] = 0;
			val->image[4 * FENETRE * y + 4 * x + 1] = 0;
			val->image[4 * FENETRE * y + 4 * x + 2] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	if (val->ligne == 1 || val->ligne == 2)
		relier(*val);
	else
		ft_point(val);
	mlx_put_image_to_window(val->mlx[0], val->mlx[1], val->p_image, 0, 0);
	return (0);
}
