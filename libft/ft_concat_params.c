/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:30:24 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 18:27:17 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		l;
	int		j;
	char	*a;

	a = "\0";
	j = 0;
	l = 0;
	i = 2;
	if (argc == 1)
		return (a);
	while (i < argc)
	{
		l = l + ft_strlen(argv[i]);
		i++;
	}
	argv[i] = malloc(sizeof(char) * l + 1);
	i = 2;
	while (i < argc)
	{
		ft_strcat(argv[1], argv[i]);
		i++;
	}
	return (argv[1]);
}
