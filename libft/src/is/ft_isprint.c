/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:09:17 by apouchet          #+#    #+#             */
/*   Updated: 2018/11/27 17:09:21 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}