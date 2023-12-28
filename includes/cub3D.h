/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:54 by anlima            #+#    #+#             */
/*   Updated: 2023/12/28 20:33:16 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ARG_ERROR "Invalid arguments!\nUsage => ./cub3D <.cub_file>\n"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define ESC 65307
# define IMG_SIZE 64
# define WIDTH 640
# define HEIGHT 640

typedef struct s_pos
{
	int		x;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	cam_x;
	double	cam_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	wall_x;
	double	plane_x;
	double	plane_y;
	double	draw_end;
	double	ray_dir_x;
	double	ray_dir_y;
	double	draw_start;
	double	line_height;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}			t_pos;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		width;
	int		height;
	int		endian;
}			t_img;

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
	int		floor;
	int		ceiling;
	void	*mlx;
	void	*mlx_win;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}			t_win;

typedef struct s_line
{
	int		x;
	int		y;
	int		y0;
	int		y1;
	int		tex_x;
	int		tex_y;
}			t_line;

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
// imgs
int			render(void);
void		init_texture(void);
void		img_pix_put(int x, int y, int rgb);
// raycaster
void		raycaster(void);
// scaling
void		img_scaling(void);
// win general
void		convert_rgb(void);
int			encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
// hooks
int			keyhooks(int keycode);
// structs
void		set_images(void);
// general
t_map		*map(void);
t_win		*win(void);
t_img		*img(void);
t_pos		*pos(void);
t_line		*line(void);
// utils
void		clean_mallocs(void);
int			get_flag(char *line);
void		free_dptr(char **str);
void		finish_execution(void);
char		*ft_strjoin_char(char *str, char c);

#endif