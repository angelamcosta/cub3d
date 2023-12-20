/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:59 by anlima            #+#    #+#             */
/*   Updated: 2023/12/20 16:53:41 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_images(void);
int		render_rect(void);

void	set_images(void)
{
	int	size;

	size = IMG_SIZE;
	(img()->north) = mlx_xpm_file_to_image(win()->mlx, map()->no, &size, &size);
	(img()->south) = mlx_xpm_file_to_image(win()->mlx, map()->so, &size, &size);
	(img()->east) = mlx_xpm_file_to_image(win()->mlx, map()->ea, &size, &size);
	(img()->west) = mlx_xpm_file_to_image(win()->mlx, map()->we, &size, &size);
}

int	render_rect(void)
{
	int	i;
	int	j;

	if (win()->mlx_win == NULL)
		return (1);
	convert_rgb();
	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
			mlx_pixel_put(win()->mlx, win()->mlx_win, j++, i, img()->ceiling);
		++i;
	}
	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			mlx_pixel_put(win()->mlx, win()->mlx_win, j++, i, img()->floor);
		++i;
	}
	return (0);
}
