/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:55:56 by jaandras          #+#    #+#             */
/*   Updated: 2025/04/02 17:58:26 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


# define BPP sizeof(int32_t)

typedef struct s_mytext
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*guy;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
}	t_mytext;

typedef	struct s_myimag
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*guy;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
}	t_myimag;

typedef struct s_begin
{
	char	**map;
	int		height;
	int		width;
}	t_begin;

typedef struct s_game
{
	char	**map;
	char	*path;
	int		height;
	int		width;
	int		p;
	int		c;
	int		e;
	int		err;
	int		comp_p;
	int		comp_c;
	int		comp_e;

	mlx_t	*mlx;
	struct s_mytext	*text;
	struct s_myimag	*img;
	int		moves;
}	t_game;


int	ft_pars_map(t_game *game, t_begin *begin);
void	ft_map_array(int lines, int fd, t_game *game, t_begin *begin);
int	ft_count_lines(int fd);
int	ft_width_check(t_game *game);
size_t	ft_maplen(const char *s);
int     ft_walls_check(t_game *game);
int     ft_check_gamebility(t_game *game, t_begin *begin);
void    ft_fill_map(t_game *game, t_begin *begin);
void	ft_free_map(t_game *game, t_begin *begin);
char	*ft_strdup(const char *s);
int		ft_check_extencion(char *str);

void    my_keyhook(mlx_key_data_t keydata, void *param);
int		ft_get_textures(t_game *data);
int		ft_get_images(t_game *data);
void     ft_make_map(t_game *data);
void     ft_make_floor(t_game *data);
void	ft_delete_collect(t_game *data);
void	ft_pass_exit(t_game *data);
void	ft_free_visual(t_game *game);



#endif