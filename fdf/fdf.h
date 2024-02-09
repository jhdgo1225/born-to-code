/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:37:54 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 17:16:12 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx/mlx.h"
# include "libft/libft/libft.h"
# include "libft/ft_printf_project/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_map_coord
{
	double	x;
	double	y;
	double	z;
	int		map_x;
	int		map_y;
	int		opacity;
	int		red;
	int		green;
	int		blue;
}				t_map_coord;

typedef struct s_map
{
	int			row;
	int			column;
	t_map_coord	*coords;
}				t_map;

void			check_args(int argc, char **argv);
void			init_maps(t_map *map, char *file);
int				check_hex(char *str);
int				check_hex_last(char *str);
int				check_num(char *str);
int				check_num_last(char *str);
int				calc_ret_wd_cnt(char **parse);
int				calc_width(char *str);
void			free_perfectly_on_main(char **words);
int				count_words(char **strs);
int				open_maps(char *file);
int				parse_fdf_file_line(t_map *map, int line_idx, char *str);
void			transform_rotation(t_map_coord *coords, int size);
void			present_isometric(t_map_coord *coords, int row, int col);
void			draw_maps(t_map *map, t_mlx *vars);
void			draw_lines(t_map_coord *coords, int row, int col, t_image *img);
void			put_pixel(t_image *img, int x, int y, unsigned int color);
unsigned int	lerp_color(t_map_coord *p1, t_map_coord *p2, int s_x, int s_y);
void			loop_maps(t_mlx *vars);
int				sign(int a);
int				abs(int a);

#endif
