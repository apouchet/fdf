/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:30:09 by apouchet          #+#    #+#             */
/*   Updated: 2019/10/24 09:24:53 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_vol(t_val *val)
{
	if (val->key[69] || val->key[44])
	{
		if (val->len < 150)
			if (val->coef < 100)
				val->coef++;
		if (val->len < 300)
			if (val->coef < 50)
				val->coef++;
		if (val->len > 300)
			if (val->coef < 20)
				val->coef++;
	}
	if (val->key[78] || val->key[47])
		if (val->coef > 1)
			val->coef--;
	if (val->key[88] || val->key[41])
		if (val->vol > 0)
			val->vol--;
	if (val->key[92] || val->key[39])
		if (val->vol < 20)
			val->vol++;
}

void	key_fleche(t_val *val)
{
	if (val->key[126])
		val->y -= 5;
	if (val->key[125])
		val->y += 5;
	if (val->key[124])
		val->x += 5;
	if (val->key[123])
		val->x -= 5;
}

void	key_rot(t_val *val)
{
	if (val->key[12] == 1)
		val->rotp = val->rotp + 360 / 100;
	if (val->key[14] == 1)
		val->rotp = val->rotp - 360 / 100;
	if (val->key[1] == 1)
		val->rotv = val->rotv + 360 / 100;
	if (val->key[13] == 1)
		val->rotv = val->rotv - 360 / 100;
	if (val->key[2] == 1)
		val->roth = val->roth - 360 / 100;
	if (val->key[0] == 1)
		val->roth = val->roth + 360 / 100;
	if (val->roth == 360 || val->roth == -360)
		val->roth = 0;
	if (val->rotv == 360 || val->rotv == -360)
		val->rotv = 0;
	if (val->rotp == 360 || val->rotp == -360)
		val->rotv = 0;
}

int		ft_key(t_val *val)
{
	if (val->key[49])
	{
		val->roth = 0;
		val->rotv = 0;
		val->rotp = 0;
	}
	if (val->key[53] == 1)
		ft_exit(val, 0);
	key_vol(val);
	key_rot(val);
	key_fleche(val);
	ft_rot(val);
	ft_draw(val);
	return (0);
}
