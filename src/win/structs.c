/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:59 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 13:05:35 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_images(void);

void	set_images(void)
{
	int	size;

	size = IMG_SIZE;
	(win()->north) = mlx_xpm_file_to_image(win()->mlx, map()->no, &size, &size);
	(win()->south) = mlx_xpm_file_to_image(win()->mlx, map()->so, &size, &size);
	(win()->east) = mlx_xpm_file_to_image(win()->mlx, map()->ea, &size, &size);
	(win()->west) = mlx_xpm_file_to_image(win()->mlx, map()->we, &size, &size);
}
