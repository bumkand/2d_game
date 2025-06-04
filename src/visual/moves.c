/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:44:19 by jakand            #+#    #+#             */
/*   Updated: 2025/04/02 18:25:46 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_up(t_game *data)
{
	if (data->map[(data->img->guy->instances[0].y - 60)
			/ 60][(data->img->guy->instances[0].x) / 60] == '1')
		return ;
	data->img->guy->instances[0].y -= 60;
	ft_printf("%i\n", data->moves++);
}

void	ft_key_down(t_game *data)
{
	if (data->map[(data->img->guy->instances[0].y + 60)
			/ 60][(data->img->guy->instances[0].x) / 60] == '1')
		return ;
	data->img->guy->instances[0].y += 60;
	ft_printf("%i\n", data->moves++);
}

void	ft_key_left(t_game *data)
{
	if (data->map[(data->img->guy->instances[0].y)
			/ 60][(data->img->guy->instances[0].x - 60) / 60] == '1')
		return ;
	data->img->guy->instances[0].x -= 60;
	ft_printf("%i\n", data->moves++);
}

void	ft_key_right(t_game *data)
{
	if (data->map[(data->img->guy->instances->y)
			/ 60][(data->img->guy->instances->x + 60) / 60] == '1')
		return ;
	data->img->guy->instances->x += 60;
	ft_printf("%i\n", data->moves++);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_key_up(data);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_key_down(data);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_key_left(data);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_key_right(data);
	ft_delete_collect(data);
	ft_pass_exit(data);
}
