/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gamebility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:49:42 by jakand            #+#    #+#             */
/*   Updated: 2025/04/02 22:06:43 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_place(char *zone, t_game *game, t_begin *begin, int i)
{
	int	j;

	j = 0;
	while (zone[j] != '\0')
	{
		if (zone[j] == 'P')
		{
			game->p++;
			begin->width = j;
			begin->height = i;
		}
		if (zone[j] == 'C')
			game->c++;
		if (zone[j] == 'E')
			game->e++;
		if (zone[j] != 'P' && zone[j] != 'C' && zone[j] != 'E' && zone[j] != '1'
			&& zone[j] != '0')
			game->err++;
		j++;
	}
	// printf("\nt_game game -> P= %i C= %i E= %i err= %i\n", game->p, game->c,
	// 	game->e, game->err);
}

int	ft_check_game(t_game *game, t_begin *begin)
{
	int	i;

	i = 1;
	while (begin->map[i] != NULL)
	{
		ft_check_place(begin->map[i], game, begin, i);
		i++;
	}
	if (game->p != 1 || game->e != 1 || game->c == 0 || game->err != 0)
		return (ft_printf("Wrong amount of 'P' 'C' 'E' characters or wrong characters are included\n"), 0);
	return (1);
}

int	ft_check_gamebility(t_game *game, t_begin *begin)
{
	// int	i;

	// i = 0;
	// while (begin->map[i] != NULL)
	// {
	// 	printf("begin map %s\n", begin->map[i]);
	// 	i++;
	// }
	// printf("\nstart checking %i x %i\n", begin->width, begin->height);
	// printf("\n%i x %i\n", game->width, game->height);
	if (!(ft_check_game(game, begin)))
		return (0);
	// printf("\nStart t_game comp-> P= %i C= %i E= %i\n", game->comp_p,
		// game->comp_c, game->comp_e);
	ft_fill_map(game, begin);
	if (game->p != game->comp_p || game->c != game->comp_c
		|| game->e != game->comp_e)
		return (ft_printf("No possibility to collect everything or win game\n"), 0);
	// i = 0;
	// while (begin->map[i] != NULL)
	// {
	// 	printf("next begin %s\n", begin->map[i]);
	// 	i++;
	// }
	// printf("\nAfter check t_game comp-> P= %i C= %i E= %i\n", game->comp_p,
	// 	game->comp_c, game->comp_e);
	// printf("\nstart checking %i x %i\n", begin->width, begin->height);
	// printf("\n%i x %i\n", game->width, game->height);
	return (1);
}
