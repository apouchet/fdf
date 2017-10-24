/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:35:39 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/13 18:36:18 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_val *val, t_angle b, int x, int y)
{
	int	ax;
	int	ay;
	int	az;

	val->tab[y][x][0] = ((-(val->len / 2) + x) * val->coef);
	val->tab[y][x][1] = ((-(val->nb / 2) + y) * val->coef);
	val->tab[y][x][2] = (((val->tab[y][x][3]) * (val->vol)) * val->coef / 20);
	ax = val->tab[y][x][0];
	ay = val->tab[y][x][1];
	az = val->tab[y][x][2];
	val->tab[y][x][1] = val->tab[y][x][1] * cosf(b.anglex) -
	az * sinf(b.anglex);
	val->tab[y][x][2] = val->tab[y][x][2] * cosf(b.anglex) +
	ay * sinf(b.anglex);
	ay = val->tab[y][x][1];
	az = val->tab[y][x][2];
	val->tab[y][x][0] = val->tab[y][x][0] * cosf(b.angley) -
	az * sinf(b.angley);
	val->tab[y][x][2] = val->tab[y][x][2] * cosf(b.angley) +
	ax * sinf(b.angley);
	ax = val->tab[y][x][0];
	val->tab[y][x][0] = val->x + val->tab[y][x][0] * cosf(b.anglez) -
	ay * sinf(b.anglez);
	val->tab[y][x][1] = val->y + val->tab[y][x][1] * cosf(b.anglez) +
	ax * sinf(b.anglez);
}

void	ft_rot(t_val *val)
{
	int				x;
	int				y;
	struct s_angle	b;

	x = 0;
	y = 0;
	b.anglez = (M_PI * val->rotp) / 180;
	b.anglex = (M_PI * val->rotv) / 180;
	b.angley = (M_PI * val->roth) / 180;
	while (y < val->nb - 1)
	{
		while (val->tab[y][x][3] != -10000)
		{
			rotation(val, b, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
