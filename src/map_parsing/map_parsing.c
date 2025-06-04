/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:46:17 by jaandras          #+#    #+#             */
/*   Updated: 2025/04/02 21:59:08 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd)
{
	char	*str;
	int		lines;

	lines = 0;
	if (fd < 0)
		return (ft_printf("Error when opening file\n"), 0);
	str = get_next_line(fd);
	if (!str)
		return (ft_printf("Nothing in the map file\n"), 0);
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	ft_map_array(int lines, int fd, t_game *game, t_begin *begin)
{
	int		i;
	char	*str;

	i = 0;
	fd = open(game->path, O_RDONLY);
	game->map = malloc((lines + 1) * sizeof(char *));
	begin->map = malloc((lines + 1) * sizeof(char *));
	if (!game->map || !begin->map)
		return (perror("Map didn't allocate"));
	str = get_next_line(fd);
	while (str)
	{
		game->map[i] = str;
		if (game->map[i][ft_maplen(game->map[i])] == '\n')
			game->map[i][ft_maplen(game->map[i])] = '\0';
		begin->map[i] = ft_strdup(game->map[i]);
		i++;
		str = get_next_line(fd);
	}
	game->map[i] = NULL;
	begin->map[i] = NULL;
	close(fd);
}

int	ft_check_extencion(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && str[i
			- 3] == '.')
		return (1);
	return (0);
}

void	ft_make_struct(t_game *game, t_begin *begin)
{
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->err = 0;
	game->comp_p = 0;
	game->comp_c = 0;
	game->comp_e = 0;
	begin->width = 1;
	begin->height = 1;
	game->moves = 1;
}

int	ft_pars_map(t_game *game, t_begin *begin)
{
	int	fd;
	// int	i;

	ft_make_struct(game, begin);
	fd = open(game->path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error when opening file\n"), 0);
	game->height = ft_count_lines(fd);
	if (game->height == 0)
		return (0);
	// ft_printf("%i\n", game->height);
	close(fd);
	ft_map_array(game->height, fd, game, begin);
	game->width = ft_maplen(game->map[0]);
	// ft_printf("%i\n", game->width);
	if (!(ft_width_check(game)) || !(ft_walls_check(game)))
		return (ft_free_map(game, begin), 0);
	if (!(ft_check_gamebility(game, begin)))
		return (ft_free_map(game, begin), 0);
	// printf("\nt_game game -> P= %i C= %i E= %i err= %i\n", game->p, game->c,
	// 	game->e, game->err);
	// i = 0;
	// while (game->map[i])
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
	return (1);
}
