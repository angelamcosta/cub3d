/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:27 by anlima            #+#    #+#             */
/*   Updated: 2024/01/09 20:53:58 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

static void	init_vars(void);

static void	init_vars(void)
{
	map()->pos[0] = '-';
	map()->pos[1] = '-';
	map()->pos[2] = '-';
}

void	test_maps(void)
{
	for (int i = 0; i < 3; i++)
	{
		printf("ceiling[%i] -> %s\n", i, map()->ceiling[i]);
		printf("floor[%i] -> %s\n", i, map()->floor[i]);
	}
	printf("NO -> %s\n", map()->no);
	printf("SO -> %s\n", map()->so);
	printf("EA -> %s\n", map()->ea);
	printf("WE -> %s\n", map()->we);
	for (int i = 0; i < map()->rows; i++)
		printf("map[%i] ->\t|%s|\n", i, map()->map[i]);
	printf("DEBUG: rows => %i\tcols => %i\n", map()->rows, map()->cols);
}

void	init_pos(void)
{
	win()->player = (t_player *)malloc(sizeof(t_player));
	win()->player->dir_vect.x = 0;
	win()->player->dir_vect.y = 0;
	win()->player->cam_plane_vect.x = 0;
	win()->player->cam_plane_vect.y = 0;
	win()->player->pos.x = 5;
	win()->player->pos.y = 5;
	win()->player->sens = 0.1;
	win()->player->speed = 0.05;
	win()->player->cam_height = 1.0;
	add_player();
}

// TODO : - Replace the use of static func by using var

int	main(int argc, char **argv)
{
	init_vars();
	if (argc != 2 || !verify_map(argv[1]))
		return (write(2, ARG_ERROR, 49));
	if (!read_args(argv[1]))
		return (write(1, "error\n", 7));
	set_row_col();
	if (!is_map_closed() || !is_valid_path())
		return (write(1, "error\n", 7));
	convert_rgb();
	init_instance();
	init_pos();
	mlx_hook(win()->mlx_win, 2, 1L << 0, keyhooks, win);
	mlx_loop_hook(win()->mlx, &render, win());
	mlx_loop(win()->mlx);
	finish_execution();
	return (0);
}
