/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:58 by anlima            #+#    #+#             */
/*   Updated: 2024/01/09 21:31:39 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		img_scaling(t_pos *pos, t_player *player);
static void	paint_line(t_line *line, int color);
static void	texture_on_img(t_line *line, t_pos *pos, t_img *wall);
static void	paint_texture(t_line *line, t_pos *pos, double wall_x);
static void	draw_texture_image(t_line *line, t_pos *pos, t_img *img);

void	img_scaling(t_pos *pos, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof (t_line));
	ft_bzero(line, sizeof(t_line));
	if (pos->side == WEST || pos->side == EAST)
		wall_x = player->pos.y + pos->prep_wall_dist * pos->ray_dir_y;
	else
		wall_x = player->pos.x + pos->prep_wall_dist * pos->ray_dir_x;
	wall_x -= floor(wall_x);
	line->x = pos->curr_x;
	if (map()->map[pos->map_y][pos->map_x] == '1')
		paint_texture(line, pos,wall_x);
	line->y0 = 0;
	line->y1 = pos->draw_start;
	paint_line(line, win()->ceiling);
	line->y0 = HEIGHT;
	line->y1 = pos->draw_end;
	paint_line(line, win()->floor);
	free(line);
}

static void	paint_line(t_line *line, int color)
{
	int	i;
	int	j;

	if (line->y0 < line->y1)
	{
		i = line->y0;
		j = line->y1;
	}
	else
	{
		i = line->y1;
		j = line->y0;
	}
	if (i >= 0)
	{
		while (i < j)
			img_pix_put(line->x, i++, color);
	}
}

static void	paint_texture(t_line *line, t_pos *pos, double wall_x)
{
	t_img	*img;
	int		tex_x;

	if (pos->side == EAST)
		img = win()->east;
	else if (pos->side == WEST)
		img = win()->west;
	else if (pos->side == NORTH)
		img = win()->north;
	else if (pos->side == SOUTH)
		img = win()->south;
	tex_x = (int)(wall_x * (double)img->width);
	if ((pos->side == WEST || pos->side == EAST) && pos->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((pos->side == NORTH || pos->side == SOUTH) && pos->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = pos->draw_start;
	line->y1 = pos->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(line, pos, img);
}

static void	draw_texture_image(t_line *line, t_pos *pos, t_img *img)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		line->y--;
		printf("y0 -> %i\ty1 -> %i\ty_max -> %i\ty => %i\n", line->y0, line->y1, y_max, line->y);
		while (++line->y < y_max)
			texture_on_img(line, pos, img);
	}
}

static void	texture_on_img(t_line *line, t_pos *pos, t_img *wall)
{
	int	scale;

	scale = line->y * wall->line_len - (HEIGHT * win()->player->cam_height)
		* wall->line_len / 2 + pos->line_height * wall->line_len / 2;
	line->tex_y = ((scale * wall->height) / pos->line_height)
		/ wall->line_len;
	win()->mlx_img->addr[line->y * win()->mlx_img->line_len + line->x
		* win()->mlx_img->bpp / 8] = wall->addr[line->tex_y * wall->line_len
		+ line->tex_x * (wall->bpp / 8)];
	win()->mlx_img->addr[line->y * win()->mlx_img->line_len + line->x
		* (win()->mlx_img->bpp / 8) + 1] = wall->addr[line->tex_y
		* wall->line_len + line->tex_x * (wall->bpp / 8) + 1];
	win()->mlx_img->addr[line->y * win()->mlx_img->line_len + line->x
		* (win()->mlx_img->bpp / 8) + 2] = wall->addr[line->tex_y
		* wall->line_len + line->tex_x * (wall->bpp / 8) + 2];
}
