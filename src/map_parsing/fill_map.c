/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:24:37 by jakand            #+#    #+#             */
/*   Updated: 2025/04/01 19:05:31 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_value(t_game *game, t_begin *begin)
{
	if (begin->map[begin->height][begin->width] == 'P')
		game->comp_p++;
	if (begin->map[begin->height][begin->width] == 'C')
		game->comp_c++;
	if (begin->map[begin->height][begin->width] == 'E')
		game->comp_e++;
	begin->map[begin->height][begin->width] = '1';
}

int	ft_is_valid(t_game *game, t_begin *begin)
{
	char	next_value;

	if (begin->width < 0 || begin->width >= game->width || begin->height < 0
		|| begin->height >= game->height)
		return (-1);
	next_value = begin->map[begin->height][begin->width];
	if (next_value == '1')
		return (-1);
	return (1);
}

void	ft_set_arr(t_begin *arr, t_begin *begin)
{
	arr[0].width = begin->width;
	arr[0].height = begin->height + 1;
	arr[0].map = begin->map;
	arr[1].width = begin->width;
	arr[1].height = begin->height - 1;
	arr[1].map = begin->map;
	arr[2].width = begin->width + 1;
	arr[2].height = begin->height;
	arr[2].map = begin->map;
	arr[3].width = begin->width - 1;
	arr[3].height = begin->height;
	arr[3].map = begin->map;
}

void	ft_fill_map(t_game *game, t_begin *begin)
{
	t_begin	arr[4];
	int		i;

	if ((ft_is_valid(game, begin)) == 1)
	{
		ft_change_value(game, begin);
		ft_set_arr(arr, begin);
		i = 0;
		while (i < 4)
		{
			ft_fill_map(game, &arr[i]);
			i++;
		}
	}
}