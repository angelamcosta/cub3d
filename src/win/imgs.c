/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:40 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 15:55:32 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		render(void);
int		paint_background(void);
void	img_pix_put(t_img *img, int x, int y, int color);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	paint_background(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(&(win()->bg), j++, i, win()->ceiling);
		++i;
	}
	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(&(win()->bg), j++, i, win()->floor);
		++i;
	}
	return (0);
}

int	render(void)
{
	if (win()->mlx_win == NULL)
		return (1);
	while (pos()->x < WIDTH)
		raycaster();
	paint_background();
	mlx_put_image_to_window(win()->mlx, win()->mlx_win, win()->bg.mlx_img,
		0, 0);
	return (0);
}
