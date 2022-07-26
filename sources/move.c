/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:47 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 23:39:22 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animate_player(int keycode);
static void	collisions(void);

/*checks what key have been pressed and the updates the player location*/
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

/*open the player's sprite for animation*/
void	open_players(void)
{
	int	img_width;
	int	img_height;

	img_height = PX;
	img_width = PX;
	(img()->play_mv.player_a[0]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_A_0.xpm", &img_height, &img_width);
	(img()->play_mv.player_a[1]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_A_1.xpm", &img_height, &img_width);
	(img()->play_mv.player_d[0]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_D_0.xpm", &img_height, &img_width);
	(img()->play_mv.player_d[1]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_D_1.xpm", &img_height, &img_width);
	(img()->play_mv.player_s[0]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_S_0.xpm", &img_height, &img_width);
	(img()->play_mv.player_s[1]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_S_1.xpm", &img_height, &img_width);
	(img()->play_mv.player_w[0]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_W_0.xpm", &img_height, &img_width);
	(img()->play_mv.player_w[1]) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player_W_1.xpm", &img_height, &img_width);
}

/*changes what player image will be printed on the screen at that time*/
static void	animate_player(int keycode)
{
	static int	i = 0;

	i = !i;
	if (keycode == key_W)
		img()->player = img()->play_mv.player_w[i];
	if (keycode == key_S)
		img()->player = img()->play_mv.player_s[i];
	if (keycode == key_A)
		img()->player = img()->play_mv.player_a[i];
	if (keycode == key_D)
		img()->player = img()->play_mv.player_d[i];
}

/*Deals with collisions with the collectables,
enemies (ending the game) and
exit (declaring a win when the player have all the collectables)*/
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
