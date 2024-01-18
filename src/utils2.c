/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:36:15 by mpedroso          #+#    #+#             */
/*   Updated: 2024/01/18 17:46:36 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_pos(int x);
void	allocate_imgs(void);
void	init_instance(void);
void	close_win_error(void);
void	free_int_array(int **arr);

void	close_win_error(void)
{
	free_dptr(map()->map);
	if (!win()->mlx)
	{
		printf("Error initializing mlx!\n");
	}
	if (win()->mlx && !win()->mlx_win)
	{
		mlx_destroy_display(win()->mlx);
		free(win()->mlx);
		printf("Failed to create mlx window!\n");
	}
	exit(1);
}

void	allocate_imgs(void)
{
	(win()->mlx_img) = ft_calloc(1, sizeof(t_img));
	(win()->north) = ft_calloc(1, sizeof(t_img));
	(win()->south) = ft_calloc(1, sizeof(t_img));
	(win()->east) = ft_calloc(1, sizeof(t_img));
	(win()->west) = ft_calloc(1, sizeof(t_img));
	if (!win()->mlx_img || !win()->north
		|| !win()->south || !win()->east || !win()->west)
	{
		printf("Failed to allocate images, exiting!");
		exit(1);
	}
}

void	init_instance(void)
{
	win()->mlx = mlx_init();
	if (!win()->mlx)
		close_win_error();
	(win()->mlx_win) = mlx_new_window(win()->mlx, HEIGHT, WIDTH, "cub3d");
	if (!win()->mlx_win)
		close_win_error();
	init_texture();
	set_camera();
	render();
	mlx_hook(win()->mlx_win, 17, 1L << 0, close, win()->mlx_win);
	mlx_hook(win()->mlx_win, KeyPress, KeyPressMask,
		keyhooks_press, win()->mlx_win);
	mlx_hook(win()->mlx_win, KeyRelease, KeyReleaseMask,
		keyhooks_release, win()->mlx_win);
	mlx_loop_hook(win()->mlx, render, win);
	mlx_loop(win()->mlx);
}

void	free_int_array(int **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		exec_free(arr[i]);
	if (arr)
		free(arr);
	arr = NULL;
}

void	set_pos(int x)
{
	pos()->cam_x = 2 * x / (double)WIDTH - 1;
	pos()->ray_dir.x = pos()->dir.x + pos()->plane.x * pos()->cam_x;
	pos()->ray_dir.y = pos()->dir.y + pos()->plane.y * pos()->cam_x;
	pos()->delta_dist.x = fabs(1 / pos()->ray_dir.x);
	pos()->delta_dist.y = fabs(1 / pos()->ray_dir.y);
	pos()->map_x = (int)map()->pos.x;
	pos()->map_y = (int)map()->pos.y;
}
