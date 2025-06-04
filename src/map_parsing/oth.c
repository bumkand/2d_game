/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oth.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:44:03 by jakand            #+#    #+#             */
/*   Updated: 2025/04/02 18:17:21 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game, t_begin *begin)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	while (begin->map[i])
	{
		free(begin->map[i]);
		i++;
	}
	if (game->map != NULL)
		free(game->map);
	if (begin->map != NULL)
		free(begin->map);
}

void	ft_free_visual(t_game *game)
{
	if (game->img != NULL)
		free(game->img);
	if (game->text != NULL)
		free(game->text);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(s);
	j = 0;
	ptr = (char *) malloc((i + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}