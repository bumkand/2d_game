/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:16:02 by jakand            #+#    #+#             */
/*   Updated: 2025/03/31 19:20:31 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_textures(t_game *data)
{
	data->text = ft_calloc(1, sizeof(t_mytext));
	if (!(data->text))
		return (0);
	data->text->floor = mlx_load_png("images/floor.png");
	data->text->wall = mlx_load_png("images/wall.png");
	data->text->guy = mlx_load_png("images/guy.png");
	data->text->collect = mlx_load_png("images/collect.png");
	data->text->exit = mlx_load_png("images/exit.png");
	return (1);
}

int	ft_get_images(t_game *data)
{
	data->img = ft_calloc(1, sizeof(t_myimag));
	if (!(data->img))
		return (0);
	data->img->floor = mlx_texture_to_image(data->mlx, data->text->floor);
	data->img->wall = mlx_texture_to_image(data->mlx, data->text->wall);
	data->img->guy = mlx_texture_to_image(data->mlx, data->text->guy);
	data->img->collect = mlx_texture_to_image(data->mlx, data->text->collect);
	data->img->exit = mlx_texture_to_image(data->mlx, data->text->exit);
	mlx_delete_texture(data->text->floor);
	mlx_delete_texture(data->text->wall);
	mlx_delete_texture(data->text->guy);
	mlx_delete_texture(data->text->collect);
	mlx_delete_texture(data->text->exit);
	return (1);
}

void	ft_make_floor(t_game *data)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			mlx_image_to_window(data->mlx, data->img->floor, x * 60, y * 60);
			if (data->map[y][x] == '1')
				mlx_image_to_window(data->mlx, data->img->wall, x * 60, y * 60);
			if (data->map[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->img->exit, x * 60 + 12, y
					* 60 + 12);
			x++;
		}
		y++;
	}
}

void	ft_make_map(t_game *data)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	ft_make_floor(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
				mlx_image_to_window(data->mlx, data->img->guy, x * 60 + 5, y
					* 60 + 2);
			if (data->map[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->img->collect, x * 60 + 15,
					y * 60 + 15);
			x++;
		}
		y++;
	}
}
