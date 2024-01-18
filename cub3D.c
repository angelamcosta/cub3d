/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:27 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:15:59 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

static int	has_player(void)
{
	return ((map()->player == 'N'
			|| map()->player == 'S'
			|| map()->player == 'E'
			|| map()->player == 'W'));
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !verify_map(argv[1]))
		return (write(2, ARG_ERROR, 49));
	if (!read_args(argv[1]))
	{
		clean_mallocs();
		return (write(1, "error\n", 7));
	}
	set_row_col();
	if (!is_map_closed() || !is_valid_path() || !has_player())
	{
		clean_mallocs();
		return (write(1, "error\n", 7));
	}
	init_instance();
	finish_execution();
	return (0);
}
