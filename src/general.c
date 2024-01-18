/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:22:21 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:02:57 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*map(void);
t_pos	*pos(void);
t_win	*win(void);
void	free_images(void);
void	exec_free(void *ptr);

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

t_pos	*pos(void)
{
	static t_pos	pos;

	return (&pos);
}

void	exec_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	if (ptr)
		free(ptr);
}

void	free_images(void)
{
	if (win()->north)
		exec_free(win()->north->px_data);
	if (win()->east)
		exec_free(win()->east->px_data);
	if (win()->west)
		exec_free(win()->west->px_data);
	if (win()->south)
		exec_free(win()->south->px_data);
}
