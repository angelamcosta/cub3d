/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:40 by anlima            #+#    #+#             */
/*   Updated: 2023/12/29 19:24:27 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int			render(void);
void		init_texture(void);
void		img_pix_put(int x, int y, int rgb);
static void	create_texture_img(char *path, t_img *img);

int	render(void)
{
	if (win()->mlx_win == NULL)
		return (1);
	init_texture();
	while (pos()->x < WIDTH)
		raycaster();
	return (0);
}

void	img_pix_put(int x, int y, int rgb)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	win()->mlx_img->addr[y * win()->mlx_img->line_len + x * win()->mlx_img->bpp
		/ 8] = b;
	win()->mlx_img->addr[y * win()->mlx_img->line_len + x * win()->mlx_img->bpp
		/ 8 + 1] = g;
	win()->mlx_img->addr[y * win()->mlx_img->line_len + x * win()->mlx_img->bpp
		/ 8 + 2] = r;
}

void	init_texture(void)
{
	win()->mlx_img = (t_img *)malloc(sizeof(t_img));
	ft_bzero(win()->mlx_img, sizeof(t_img));
	(win()->mlx_img)->mlx_img = mlx_new_image(win()->mlx, WIDTH, HEIGHT);
	win()->mlx_img->width = WIDTH;
	win()->mlx_img->height = HEIGHT;
	win()->mlx_img->addr = mlx_get_data_addr(win()->mlx_img->mlx_img,
		&win()->mlx_img->bpp, &win()->mlx_img->line_len,
		&win()->mlx_img->endian);
	win()->north = (t_img *)malloc(sizeof(t_img));
	ft_bzero(win()->north, sizeof(t_img));
	create_texture_img(map()->no, win()->north);
	win()->south = (t_img *)malloc(sizeof(t_img));
	ft_bzero(win()->south, sizeof(t_img));
	create_texture_img(map()->so, win()->south);
	win()->east = (t_img *)malloc(sizeof(t_img));
	create_texture_img(map()->ea, win()->east);
	ft_bzero(win()->east, sizeof(t_img));
	win()->west = (t_img *)malloc(sizeof(t_img));
	ft_bzero(win()->west, sizeof(t_img));
	create_texture_img(map()->we, win()->west);
}

static void	create_texture_img(char *path, t_img *img)
{
	int	width;
	int	height;

	img->mlx_img = mlx_xpm_file_to_image(win()->mlx, path, &width, &height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img, &img->bpp, &img->line_len, &img->endian);
}
