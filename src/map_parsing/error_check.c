/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:27:59 by jakand            #+#    #+#             */
/*   Updated: 2025/04/02 22:07:39 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_walls_check(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		if (game->map[i + 1] == NULL)
			break ;
		if (game->map[i][0] == '1' && game->map[i][game->width - 1] == '1')
		{
			i++;
			continue ;
		}
		return (ft_printf("Wall is missing\n"), 0);
	}
	j = 0;
	while (game->map[0][j] == '1' && game->map[i][j] == '1' && j < game->width)
		j++;
	if (j != game->width)
		return (ft_printf("Wall is missing\n"), 0);
	return (1);
}

size_t	ft_maplen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_width_check(t_game *game)
{
	int	comp;
	int	len;

	comp = 1;
	while (comp < game->height)
	{
		len = ft_maplen(game->map[comp]);
		// ft_printf("0  %i\n", game->width);
		// ft_printf("%i  %i\n\n", comp, len);
		if (game->width != len)
			return (ft_printf("Map is not rectangular\n"), 0);
		comp++;
	}
	return (1);
}
