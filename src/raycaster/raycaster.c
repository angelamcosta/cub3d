/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:45:48 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:38:32 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int					render(void);
static void			raycaster(void);
static unsigned int	rgb_to_hex(int flag);
static void			paint_background(void);
static void			set_image_pixel(int x, int y, int color);

// checks for user input to move or rotate the player
// calls the `raycaster` function and then paints the background.
int	render(void)
{
	if (win()->keys.w)
		move('W', 1);
	if (win()->keys.d)
		move('D', 1);
	if (win()->keys.a)
		move('A', -1);
	if (win()->keys.s)
		move('S', -1);
	if (win()->keys.left)
		rotate(-1);
	if (win()->keys.right)
		rotate(1);
	raycaster();
	paint_background();
	return (0);
}

// responsible for casting rays and generating the main image
// iterates over each column of the screen, performs ray casting
// and calls functions to apply textures to the pixels
static void	raycaster(void)
{
	int		x;
	t_img	*img;

	x = -1;
	pos()->pos.x = map()->pos.x;
	pos()->pos.y = map()->pos.y;
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

// sets the color of a pixel in the image buffer
static void	set_image_pixel(int x, int y, int color)
{
	int	pixel;

	pixel = y * (win()->mlx_img->line_len / 4) + x;
	win()->mlx_img->addr[pixel] = color;
}

// convert RGB values to a hexadecimal color code
static unsigned int	rgb_to_hex(int flag)
{
	if (flag)
		return (ft_atoi(map()->ceiling[0]) * 65536 + ft_atoi(map()->ceiling[1])
			* 256 + ft_atoi(map()->ceiling[2]));
	return (ft_atoi(map()->floor[0]) * 65536 + ft_atoi(map()->floor[1]) * 256
		+ ft_atoi(map()->floor[2]));
}

// fills the background of the screen with floor
// and ceiling colors and the pixel data
// obtained from the raycaster function
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
	mlx_put_image_to_window(win()->mlx, win()->mlx_win, win()->mlx_img->mlx_img,
		0, 0);
}
