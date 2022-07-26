/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:47 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 20:18:56 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animate_player(int keycode);
static void	collisions(void);

int	move_player(int keycode)
{
	int	x;
	int	y;

	x = game()->player.x;
	y = game()->player.y;
	if (keycode == key_A && infos()->map[y][x - 1] != '1')
		game()->player.x--;
	else if (keycode == key_D && infos()->map[y][x + 1] != '1')
		game()->player.x++;
	else if (keycode == key_W && infos()->map[y - 1][x] != '1')
		game()->player.y--;
	else if (keycode == key_S && infos()->map[y + 1][x] != '1')
		game()->player.y++;
	else
		return (0);
	animate_player(keycode);
	collisions();
	return (1);
}


void	open_players(void)
{
	static int	size[2] = {PX, PX};

	(img()->play_mv.player_a[0]) = mlx_xpm_file_to_image(infos()->map,
			"./player_A_0", &size[0], &size[1]);
	(img()->play_mv.player_a[1]) = mlx_xpm_file_to_image(infos()->map,
			"./player_A_1", &size[0], &size[1]);
	(img()->play_mv.player_d[0]) = mlx_xpm_file_to_image(infos()->map,
			"./player_D_0", &size[0], &size[1]);
	(img()->play_mv.player_d[1]) = mlx_xpm_file_to_image(infos()->map,
			"./player_D_1", &size[0], &size[1]);
	(img()->play_mv.player_s[0]) = mlx_xpm_file_to_image(infos()->map,
			"./player_S_0", &size[0], &size[1]);
	(img()->play_mv.player_s[1]) = mlx_xpm_file_to_image(infos()->map,
			"./player_S_1", &size[0], &size[1]);
	(img()->play_mv.player_w[0]) = mlx_xpm_file_to_image(infos()->map,
			"./player_W_0", &size[0], &size[1]);
	(img()->play_mv.player_w[1]) = mlx_xpm_file_to_image(infos()->map,
			"./player_W_1", &size[0], &size[1]);
}

static void	animate_player(int keycode)
{
	static int	i = 0;

	i = !i;
	if (keycode == 'W')
		img()->player = img()->play_mv.player_w[i];
	if (keycode == 'S')
		img()->player = img()->play_mv.player_s[i];
	if (keycode == 'A')
		img()->player = img()->play_mv.player_a[i];
	if (keycode == 'D')
		img()->player = img()->play_mv.player_d[i];
}

static void	collisions(void)
{
	int	x;
	int	y;

	x = game()->player.x;
	y = game()->player.y;
	if (infos()->map[y][x] == 'C')
	{
		game()->collects++;
		infos()->map[y][x] = '0';
	}
	if (infos()->map[y][x] == 'E' && game()->collects == infos()->pec[2])
		game_over("you won!!!");
	if (infos()->map[y][x] == 'N')
		game_over("you lost :(");
}
