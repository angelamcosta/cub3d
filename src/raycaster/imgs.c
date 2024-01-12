/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:40 by anlima            #+#    #+#             */
/*   Updated: 2024/01/12 15:19:125 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void			init_texture(void);
int				**create_pixel_data(void);
static t_img	*create_bg_img(t_img *img);
static void		copy_pixel_data(t_img *img);
static t_img	*open_image(t_img *img, char *path);


static void	copy_pixel_data(t_img *img)
{
	int	*addr;
	int	x;
	int	y;

	addr = img->addr;
	img->px_data = ft_calloc(1, sizeof(int) * IMG_SIZE * IMG_SIZE);
	y = 0;
	while (y < IMG_SIZE)
	{
		x = 0;
		while (x < IMG_SIZE)
		{
			img->px_data[y * IMG_SIZE + x] = addr[y * IMG_SIZE + x];
			x++;
		}
		y++;
	}
	img->width = IMG_SIZE;
}

int	**create_pixel_data(void)
{
	int	i;
	int	**pixels;

	i = -1;
	pixels = ft_calloc(HEIGHT + 1, sizeof(int *));
	while (++i < HEIGHT)
		pixels[i] = ft_calloc(WIDTH + 1, sizeof(int));
	return (pixels);
}

void	init_texture(void)
{
	win()->pixel_data = create_pixel_data();
	allocate_imgs();
	open_image(win()->north, map()->no);
	open_image(win()->south, map()->so);
	open_image(win()->west, map()->we);
	open_image(win()->east, map()->ea);
	create_bg_img(win()->mlx_img);
}

static t_img	*open_image(t_img *img, char *path)
{
	int	h;
	int	w;

	h = IMG_SIZE;
	w = IMG_SIZE;
	img->mlx_img = mlx_xpm_file_to_image(win()->mlx, path, &w, &h);
	if (!img->mlx_img)
	{
		printf("Texture %s is empty or invalid!\n", path);
		free(img);
		// free rest of stuff
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	copy_pixel_data(img);
	mlx_destroy_image(win()->mlx, img->mlx_img);
	return (img);
}

static t_img	*create_bg_img(t_img *img)
{
	img->mlx_img = mlx_new_image(win()->mlx, WIDTH, HEIGHT);
	img->addr = (int *)mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	img->width = IMG_SIZE;
	return (img);
}
