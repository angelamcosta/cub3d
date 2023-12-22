/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:27 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 12:57:46 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

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
	win()->mlx = mlx_init();
	(win()->mlx_win) = mlx_new_window(win()->mlx, WIDTH, HEIGHT, "cub3D");
	(win()->bg.mlx_img) = mlx_new_image(win()->mlx, WIDTH, HEIGHT);
	(win()->bg.addr) = mlx_get_data_addr(win()->bg.mlx_img,
		&win()->bg.bpp, &win()->bg.line_len, &win()->bg.endian);
	mlx_loop_hook(win()->mlx, &render, win());
	mlx_hook(win()->mlx_win, 2, 1L << 0, keyhooks, win);
	mlx_loop(win()->mlx);
	return (0);
}
