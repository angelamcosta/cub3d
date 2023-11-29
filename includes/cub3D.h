/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:54 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 16:50:15 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ARG_ERROR "Invalid arguments!\nUsage => ./cub3D <.cub_file>\n"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**cub;
	char	**map;
	int		rows;
	int		cols;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*floor[3];
	char	*ceiling[3];
}			t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}			t_win;

// flood_fill
int			is_valid_char(char c);
int			is_closed(char **map, int rows, int cols);
int			is_valid_map(char **map, int rows, int cols);
void		handle_spaces(char **map, int rows, int cols);
// map_args
int			is_filled(void);
int			save_map(char *line);
int			split_params(char *line);
int			read_args(char *filename);
int			check_params(char **line);
// map_parser
int			is_alnum(char *filename);
int			is_empty(char *filename);
int			open_file(char *filename);
int			verify_map(char *filename);
int			check_extension(char *filename, char *extension);
// rgb
int			check_rgb(char **args);
void		save_rgb(char **rgb, char pos);
// textures
int			is_texture(char *pos);
int			check_textures(char *filename);
void		save_textures(char *pos, char *texture);
// utils
t_map		*map(void);
int			get_flag(char *line);
void		free_dptr(char **str);

#endif