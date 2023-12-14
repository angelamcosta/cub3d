/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:27 by anlima            #+#    #+#             */
/*   Updated: 2023/12/14 14:24:15 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

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
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("ceiling[%i] -> %s\n", i, map()->ceiling[i]);
	// 	printf("floor[%i] -> %s\n", i, map()->floor[i]);
	// }
	// printf("NO -> %s\n", map()->no);
	// printf("SO -> %s\n", map()->so);
	// printf("EA -> %s\n", map()->ea);
	// printf("WE -> %s\n", map()->we);
	// for (int i = 0; i < map()->rows; i++)
	// 	printf("map[%i] ->\t|%s|\n", i, map()->map[i]);
	// printf("DEBUG: rows => %i\tcols => %i\n", map()->rows, map()->cols);
	return (0);
}
