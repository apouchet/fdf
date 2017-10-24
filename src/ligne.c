/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:34:17 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/13 18:34:18 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		lenligne(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	bas_droite(t_val *val)
{
	float	taillex;
	float	tailley;
	float	pente;
	float	incli;

	taillex = val->fx - val->dx;
	tailley = val->fy - val->dy;
	pente = fabs(tailley / taillex);
	while (val->dx <= val->fx || val->dy <= val->fy)
	{
		incli = fabs((val->fy - val->dy) / (val->fx - val->dx));
		if (incli < pente + 0 && pente < 1 && val->dx < val->fx)
			ft_image(val, val->dx++, val->dy, val->zcolor);
		else if (incli > pente + 0 && pente > 1 && val->dy < val->fy)
			ft_image(val, val->dx, val->dy++, val->zcolor);
		else
			ft_image(val, val->dx++, val->dy++, val->zcolor);
		if (val->dx > val->fx || val->dy > val->fy)
			break ;
	}
}

void	bas_gauche(t_val *val)
{
	float	taillex;
	float	tailley;
	float	pente;
	float	incli;

	taillex = val->fx - val->dx;
	tailley = val->fy - val->dy;
	pente = fabs(tailley / taillex);
	while (val->dx >= val->fx || val->dy <= val->fy)
	{
		incli = fabs((val->fy - val->dy) / (val->fx - val->dx));
		if (incli < pente + 0 && pente < 1 && val->dx > val->fx)
			ft_image(val, val->dx--, val->dy, val->zcolor);
		else if (incli > pente + 0 && pente > 1 && val->dy < val->fy)
			ft_image(val, val->dx, val->dy++, val->zcolor);
		else
			ft_image(val, val->dx--, val->dy++, val->zcolor);
		if (val->dx < val->fx || val->dy > val->fy)
			break ;
	}
}

void	haut_droite(t_val *val)
{
	float	taillex;
	float	tailley;
	float	pente;
	float	incli;

	taillex = val->fx - val->dx;
	tailley = val->fy - val->dy;
	pente = fabs(tailley / taillex);
	while (val->dx <= val->fx || val->dy >= val->fy)
	{
		incli = fabs((val->fy - val->dy) / (val->fx - val->dx));
		if (incli < pente + 0 && pente < 1 && val->dx < val->fx)
			ft_image(val, val->dx++, val->dy, val->zcolor);
		else if (incli > pente + 0 && pente > 1 && val->dy > val->fy)
			ft_image(val, val->dx, val->dy--, val->zcolor);
		else
			ft_image(val, val->dx++, val->dy--, val->zcolor);
		if (val->dx > val->fx || val->dy < val->fy)
			break ;
	}
}

void	haut_gauche(t_val *val)
{
	float	taillex;
	float	tailley;
	float	pente;
	float	incli;

	taillex = val->fx - val->dx;
	tailley = val->fy - val->dy;
	pente = fabs(tailley / taillex);
	while (val->dx >= val->fx || val->dy >= val->fy)
	{
		incli = fabs((val->fy - val->dy) / (val->fx - val->dx));
		if (incli < pente + 0 && pente < 1 && val->dx > val->fx)
			ft_image(val, val->dx--, val->dy, val->zcolor);
		else if (incli > pente + 0 && pente > 1 && val->dy > val->fy)
			ft_image(val, val->dx, val->dy--, val->zcolor);
		else
			ft_image(val, val->dx--, val->dy--, val->zcolor);
		if (val->dx < val->fx || val->dy < val->fy)
			break ;
	}
}
