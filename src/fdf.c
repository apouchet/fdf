/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:30:03 by apouchet          #+#    #+#             */
/*   Updated: 2019/10/24 14:45:16 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trie_tempo(t_val *val, char **tempo, int k)
{
	int i;

	i = -1;
	if (val->len == 0)
		ft_exit(val, 1);
	while (val->len * (val->coef + 15) < FENETRE)
		val->coef++;
	while (val->len * (val->coef) > FENETRE)
		val->coef--;
	while (tempo[++i] != NULL)
	{
		if (!(val->tab[k][i] = (float*)ft_memalloc(sizeof(float) * 4)))
			exit(0);
		val->tab[k][i][0] = ((-(val->len / 2) + i) * val->coef);
		val->tab[k][i][1] = ((-(val->nb / 2) + k) * val->coef);
		val->tab[k][i][2] = ft_atoi(tempo[i]);
		val->tab[k][i][3] = val->tab[k][i][2];
		if (val->tab[k][i][3] >= val->zmax)
			val->zmax = val->tab[k][i][3];
		if (val->tab[k][i][3] < val->zmin)
			val->zmin = val->tab[k][i][3];
	}
	if (!(val->tab[k][i] = (float*)ft_memalloc(sizeof(float) * 4)))
		exit(0);
	val->tab[k][i][3] = -10000;
}

void	ft_trie(t_val *val)
{
	char	**tempo;
	int		get;
	char	*line;
	int		k;

	k = 0;
	if (!(val->tab = (float***)malloc(sizeof(float**) * (val->nb + 1))))
		exit(0);
	while ((get = get_next_line(val->fd, &line)) > 0)
	{
		tempo = ft_strsplit(line, ' ');
		if (k == 0)
			val->len = lenligne(tempo);
		if (val->len != lenligne(tempo))
			ft_exit(val, 1);
		if (!(val->tab[k] = (float**)malloc(sizeof(float*) * (val->len + 1))))
			exit(0);
		ft_trie_tempo(val, tempo, k);
		val->tab[++k] = NULL;
		free(tempo);
		free(line);
	}
	free(line);
}

int		ft_verif(t_val *val)
{
	int		get;
	char	*line;
	int		i;
	int		lettre;

	val->nb = 0;
	while ((get = get_next_line(val->fd, &line)) > 0)
	{
		i = 0;
		if (ft_strlen(line) == 0)
			ft_exit(val, 1);
		lettre = 0;
		while (line[i++])
			if (ft_isalpha(line[i]) == 1)
				lettre++;
		if (lettre - i > 0)
			ft_exit(val, 1);
		val->nb++;
		free(line);
	}
	if (val->nb < 2 && get == 0)
			ft_exit(val, 1);
	free(line);
	return (val->nb);
}

int		ft_base(char *argv, t_val *val)
{
	if ((val->fd = open(argv, O_RDONLY)) < 0)
		ft_exit(val, 1);
	if ((val->nb = ft_verif(val)) == 1)
		ft_exit(val, 1);
	close(val->fd);
	if ((val->fd = open(argv, O_RDONLY)) < 0)
		ft_exit(val, 1);
	ft_trie(val);
	close(val->fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_val		val;
	t_picture	p;

	if (argc != 2)
	{
		ft_putendl("./fdf nom fichier");
		return (0);
	}
	ft_init_fdf(&val);
	if (!(val.mlx = (void**)ft_memalloc(sizeof(void*) * 3)))
		return (-1);
	val.mlx[0] = mlx_init();
	val.mlx[1] = mlx_new_window(val.mlx[0], FENETRE, FENETRE, "mlx");
	val.p_image = mlx_new_image(val.mlx[0], FENETRE, FENETRE);
	val.image = mlx_get_data_addr(val.p_image, &p.bpp, &p.s_l, &p.endian);
	ft_base(argv[1], &val);
	mlx_hook(val.mlx[1], 2, 0, &ft_key_on, &val);
	mlx_key_hook(val.mlx[1], &ft_key_off, &val);
	mlx_loop_hook(val.mlx[0], &ft_draw, &val);
	mlx_loop(val.mlx[0]);
	return (0);
}
