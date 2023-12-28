/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:40 by anlima            #+#    #+#             */
/*   Updated: 2023/12/28 20:31:53 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int			render(void);
void		init_texture(void);
void		img_pix_put(int x, int y, int rgb);
static void	create_texture_img(char *path, t_img *img);

void	img_pix_put(int x, int y, int rgb)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img()->addr[y * img()->line_len + x * img()->bpp / 8] = b;
	img()->addr[y * img()->line_len + x * img()->bpp / 8 + 1] = g;
	img()->addr[y * img()->line_len + x * img()->bpp / 8 + 2] = r;
}

int	render(void)
{
	if (win()->mlx_win == NULL)
		return (1);
	init_texture();
	while (pos()->x < WIDTH)
		raycaster();
	return (0);
}

void	init_texture(void)
{
	create_texture_img(map()->no, &win()->north);
	create_texture_img(map()->so, &win()->south);
	create_texture_img(map()->ea, &win()->east);
	create_texture_img(map()->we, &win()->west);
}

static void	create_texture_img(char *path, t_img *img)
{
	int	width;
	int	height;

	img->mlx_img = mlx_xpm_file_to_image(win()->mlx, path, &width, &height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->addr, &img->bpp, &img->line_len,
		&img->endian);
}
