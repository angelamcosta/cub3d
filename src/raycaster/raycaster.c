/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:45:48 by anlima            #+#    #+#             */
/*   Updated: 2024/01/12 14:53:00 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int					render(void);
static void			raycaster(void);
static unsigned int	rgb_to_hex(int flag);
static void			paint_background(void);
static void			set_image_pixel(int x, int y, int color);

int	render(void)
{
	// add movements
	raycaster();
	paint_background();
	return (0);
}

static void	raycaster(void)
{
	int		x;
	t_img	*img;

	x = -1;
	pos()->pos.x = map()->pos[1];
	pos()->pos.y = map()->pos[2];
	free_int_array(win()->pixel_data);
	win()->pixel_data = create_pixel_data();
	while (++x < WIDTH)
	{
		set_pos(x);
		step();
		dda();
		camera_distance();
		prep_draw_line();
		img = select_texture();
		apply_texture(img, x);
	}
}

static void	set_image_pixel(int x, int y, int color)
{
	int	pixel;

	pixel = y * (win()->mlx_img->line_len / 4) + x;
	win()->mlx_img->addr[pixel] = color;
}

static unsigned int	rgb_to_hex(int flag)
{
	if (flag)
		return (ft_atoi(map()->ceiling[0]) * 65536 + ft_atoi(map()->ceiling[1])
			* 256 + ft_atoi(map()->ceiling[2]));
	return (ft_atoi(map()->floor[0]) * 65536 + ft_atoi(map()->floor[1]) * 256
		+ ft_atoi(map()->floor[2]));
}

static void	paint_background(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (win()->pixel_data[i][j] > 0)
				set_image_pixel(j, i, win()->pixel_data[i][j]);
			else if (i < HEIGHT / 2)
				set_image_pixel(j, i, rgb_to_hex(1));
			else
				set_image_pixel(j, i, rgb_to_hex(0));
		}
	}
	mlx_put_image_to_window(win()->mlx, win()->mlx_win, win()->mlx_img->mlx_img, 0, 0);
}
