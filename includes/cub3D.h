/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:54 by anlima            #+#    #+#             */
/*   Updated: 2023/12/15 18:06:33 by anlima           ###   ########.fr       */
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
	char	**map;
	int		rows;
	int		cols;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*floor[3];
	char	*ceiling[3];
	char	pos[3];
}			t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}			t_win;

// flood_fill
void		set_row_col(void);
int			mark_regions(void);
int			is_map_closed(void);
int			is_valid_char(char c);
void		dfs(int row, int col, char mark);
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
// parser_utils
int			is_valid_path(void);
int			is_valid_str(char *str);
int			check_char(int i, int j);
// rgb
int			check_rgb(char **args);
void		save_rgb(char **rgb, char pos);
// textures
int			is_texture(char *pos);
int			check_textures(char *filename);
int			save_textures(char *pos, char *texture);
// general
void		init_vars(void);
// utils
t_map		*map(void);
void		clean_mallocs(void);
int			get_flag(char *line);
void		free_dptr(char **str);
char		*ft_strjoin_char(char *str, char c);

#endif