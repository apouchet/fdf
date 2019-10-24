/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:40:42 by apouchet          #+#    #+#             */
/*   Updated: 2019/10/24 14:44:36 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image(t_val *val, int x, int y, int color)
{
	int pos;

	pos = 4 * FENETRE * y + 4 * x;
	if (color == 0)
		color = 1;
	if (val->col == 1)
	{
		val->image[pos] = 255 * (1 - val->b) +
		(-val->inv) * (((255) / val->zmax) * color) * val->b;
		val->image[pos + 1] = 255 * (1 - val->g) +
		(-val->inv) * (((255) / val->zmax) * color) * val->g;
		val->image[pos + 2] = 255 * (1 - val->r) +
		(-val->inv) * (((255) / val->zmax) * color) * val->r;
	}
	else
	{
		val->image[pos] = 255 * (1 - val->b) -
		(-val->inv) * (((255) / val->zmax) * color) * val->b;
		val->image[pos + 1] = 255 * (1 - val->g) -
		(-val->inv) * (((255) / val->zmax) * color) * val->g;
		val->image[pos + 2] = 255 * (1 - val->r) -
		(-val->inv) * (((255) / val->zmax) * color) * val->r;
	}
}

int		ft_key_off(int keycode, t_val *val)
{
	val->key[keycode] = 0;
	if (keycode == 3 && val->ligne == 0)
		val->ligne = 1;
	else if (keycode == 3 && val->ligne == 1)
		val->ligne = 2;
	else if (keycode == 3 && val->ligne == 2)
		val->ligne = 0;
	return (ft_key(val));
}

int		ft_key_on(int keycode, t_val *val)
{
	val->key[keycode] = 1;
	if (keycode == 15 && val->r == 0)
		val->r = 1;
	else if (keycode == 15 && val->r == 1)
		val->r = 0;
	if (keycode == 5 && val->g == 0)
		val->g = 1;
	else if (keycode == 5 && val->g == 1)
		val->g = 0;
	if (keycode == 11 && val->b == 0)
		val->b = 1;
	else if (keycode == 11 && val->b == 1)
		val->b = 0;
	if (keycode == 9 && val->inv == 0)
		val->inv = 1;
	else if (keycode == 9 && val->inv == 1)
		val->inv = 0;
	if (keycode == 45 && val->col == 0)
		val->col = 1;
	else if (keycode == 45 && val->col == 1)
		val->col = 0;
	return (ft_key(val));
}

void	ft_init_fdf(t_val *val)
{
	ft_bzero(val, sizeof(t_val));
	val->mid = FENETRE / 2;
	val->coef = 2;
	val->vol = 8;
	val->zmax = 1;
	val->r = 1;
	val->g = 1;
	val->col = 1;
	val->inv = 1;
}

void	ft_exit(t_val *val, int mode)
{
	if (mode == 1)
		ft_putendl("fichier invalide");
	free(val->tab);
	if (mode == 0)
		mlx_destroy_image(val->mlx[0], val->p_image);
	exit(0);
}
