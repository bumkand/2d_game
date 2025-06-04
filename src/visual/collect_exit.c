/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:56:59 by jaandras          #+#    #+#             */
/*   Updated: 2025/04/02 18:27:26 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_collect(t_game *data)
{
	int	i;

	// i = 0;
	// while (data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	i = 0;
	while (i < data->comp_c)
	{
		// ft_printf("Collectible: x = %i, y = %i\n",
		// 	data->img->collect->instances[i].x / 60,
		// 	data->img->collect->instances[i].y / 60);
		// ft_printf("Player: x = %i, y = %i\n", data->img->guy->instances[0].x
		// 	/ 60, data->img->guy->instances[0].y / 60);
		if ((data->img->collect->instances[i].y
				/ 60 == data->img->guy->instances->y / 60)
			&& (data->img->collect->instances[i].x
				/ 60 == data->img->guy->instances->x / 60)
			&& (data->img->collect->instances[i].enabled == true))
		{
			data->img->collect->instances[i].enabled = false;
			data->map[data->img->guy->instances->y
				/ 60][data->img->guy->instances->x / 60] = '0';
			data->c -= 1;
			// i = 0;
			// while (data->map[i])
			// {
			// 	printf("%s\n", data->map[i]);
			// 	i++;
			// }
			return ;
		}
		i++;
	}
}

void	ft_pass_exit(t_game *data)
{
	// ft_printf("Exit: x = %i, y = %i\n",
	// 	data->img->exit->instances->x / 60,
	// 	data->img->exit->instances->y / 60);
	if ((data->img->exit->instances->y / 60 == data->img->guy->instances->y
			/ 60) && (data->img->exit->instances->x
			/ 60 == data->img->guy->instances->x / 60) && data->c == 0)
		mlx_close_window(data->mlx);
}