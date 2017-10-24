/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:46:59 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/09 17:47:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ligne(t_val *val)
{
	if (val->dx < val->fx)
	{
		if (val->dy < val->fy)
			bas_droite(val);
		else
			haut_droite(val);
		return ;
	}
	else
	{
		if (val->dy < val->fy)
			bas_gauche(val);
		else
			haut_gauche(val);
	}
	return ;
}

void	ft_trace_ligne(t_val *val)
{
	if (val->dx == val->fx && val->dy != val->fy)
	{
		while (val->dy < val->fy)
			ft_image(val, val->dx, val->dy++, val->zcolor);
		while (val->dy > val->fy)
			ft_image(val, val->dx, val->dy--, val->zcolor);
		return ;
	}
	else if (val->dy == val->fy && val->dx != val->fx)
	{
		while (val->dx < val->fx)
			ft_image(val, val->dx++, val->dy, val->zcolor);
		while (val->dx > val->fx)
			ft_image(val, val->dx--, val->dy, val->zcolor);
		return ;
	}
	else
		ft_ligne(val);
	return ;
}

void	ft_diag(int x, int y, t_val *val)
{
	if (val->tab[y][x + 1][3] != -10000 && y - 1 < val->nb - 1 && y - 1 >= 0 &&
		val->ligne == 2 && val->tab[y - 1][x + 1][1] < val->mid && val->tab
		[y - 1][x + 1][0] < val->mid && val->tab[y - 1][x + 1][0] > -val->mid &&
		val->tab[y - 1][x + 1][1] > -val->mid)
	{
		if (val->zcolor < val->tab[y - 1][x + 1][3])
			val->zcolor = val->tab[y - 1][x + 1][3];
		ft_option_ligne(x, y, 2, val);
	}
}
