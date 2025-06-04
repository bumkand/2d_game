/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:18:28 by jakand            #+#    #+#             */
/*   Updated: 2025/04/02 18:24:49 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_game(t_game *data)
{
	data->mlx = mlx_init(data->width * 60, data->height * 60, "SO_LONG", false);
	if (!data->mlx)
	{
		ft_printf("MLX initialization failed");
		exit(0);
	}
	if (!(ft_get_textures(data)) || !(ft_get_images(data)))
	{
		ft_printf("Texture loading or image creation failed");
		ft_free_visual(data);
		exit(0);
	}
	ft_make_map(data);
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (1);
}

int	main(int arc, char *arv[])
{
	t_game	game;
	t_begin	begin;

	if (arc != 2 || *arv[1] == '\0')
		return (ft_printf("Not 2 arguments or nothing in 2nd argument\n"), 0);
	game.path = ft_strjoin("maps/", arv[1]);
	if (!(ft_check_extencion(game.path)))
		return (free(game.path), ft_printf("Wrong extencion\n"), 0);
	if (!(ft_pars_map(&game, &begin)))
		return (free(game.path), 0);
	// printf("\nbegin position after checking %i x %i\n", begin.width,
	// 	begin.height);
	if (!(ft_init_game(&game)))
		return (ft_free_map(&game, &begin), free(game.path), 0);
	free(game.path);
	ft_free_map(&game, &begin);
	ft_free_visual(&game);
	return (1);
}
