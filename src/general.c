/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:22:21 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 15:59:54 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*map(void);
t_win	*win(void);
t_img	*img(void);
t_pos	*pos(void);
void	init_vars(void);

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_win	*win(void)
{
	static t_win	win;

	return (&win);
}

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

t_pos	*pos(void)
{
	static t_pos	pos;

	return (&pos);
}

void	init_vars(void)
{
	map()->pos[0] = '-';
	map()->pos[1] = '-';
	map()->pos[2] = '-';
}
