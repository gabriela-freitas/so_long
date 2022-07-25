/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:47 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 23:04:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	x = game()->player.x;
	y = game()->player.y;
	if (infos()->map[y][x] == 'C')
	{
		game()->collects++;
		infos()->map[y][x] = '0';
	}
	if (infos()->map[y][x] == 'E' && game()->collects == infos()->pec[2])
		game_over("you won!!!");
	return (1);
}

//put str to image : colocar os passos na tela
