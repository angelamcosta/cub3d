/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:27 by anlima            #+#    #+#             */
/*   Updated: 2023/11/27 18:50:26 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !verify_map(argv[1]))
		return (write(2, ARG_ERROR, 49));
	if (!read_args(argv[1]))
		write(1, "error\n", 7);
	return (1);
}
