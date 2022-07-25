/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:47 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 20:01:20 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode)
{
	int	x;
	int	y;

	x = infos()->player.x;
	y = infos()->player.y;
	if (keycode == key_A && infos()->map[x - 1][y] != '1')
		infos()->player.x--;
	else if (keycode == key_D && infos()->map[x + 1][y] != '1')
		infos()->player.x++;
	else if (keycode == key_W && infos()->map[x][y - 1] != '1')
		infos()->player.y--;
	else if (keycode == key_S && infos()->map[x][y + 1] != '1')
		infos()->player.y++;
	else
		return (0);
	ft_printf("x = %d\ty = %d\n", infos()->player.x, infos()->player.y);
	return (1);
}
