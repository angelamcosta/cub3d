/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:22:21 by anlima            #+#    #+#             */
/*   Updated: 2023/12/28 19:05:32 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*map(void);
t_win	*win(void);
t_img	*img(void);
t_pos	*pos(void);
t_line	*line(void);

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

t_line	*line(void)
{
	static t_line	line;

	return (&line);
}
