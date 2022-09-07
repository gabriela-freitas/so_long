/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/09/07 14:40:28 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*It' triggered when the users presses a key
	Deals with movements (W, S, D, A)
	and closing the window when ESC is pressed*/
static int	key_code(int keycode)
{
	if (keycode == key_ESC)
		game_over("Thank you for playing");
	if (move_player(keycode))
		ft_printf("steps: %d\n", ++game()->steps);
	return (1);
}

/*It's executed all the time
printing the updated positions of the player,
the collectables and the steps*/
static int	print_player(void)
{
	char	*str;
	char	*steps;

	print_map(-1, -1);
	mlx_put_image_to_window(infos()->mlx, infos()->win_mlx,
		img()->player, game()->player.x * PX, game()->player.y * PX);
	steps = ft_itoa(game()->steps);
	str = ft_strjoin("Steps: ", steps);
	mlx_string_put(infos()->mlx, infos()->win_mlx, PX, 20, 0x00FFFFFF, str);
	free(str);
	free(steps);
	return (1);
}

/*It's triggered when the user clicks on the window's exit button*/
static int	close_win(void)
{
	game_over("Thank you for playing");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		parse_map(argv[1]);
		infos()->mlx = mlx_init();
		if (infos()->mlx)
		{
			(infos()->win_mlx) = mlx_new_window(infos()->mlx,
					PX * (infos()->width - 1), PX * infos()->height, "so_long");
		}
		if (infos()->win_mlx)
		{
			mlx_hook(infos()->win_mlx, KEY_PRESS, KeyPressMask, key_code, NULL);
			mlx_hook(infos()->win_mlx, DESTROY_NOTIFY, ButtonPressMask,
				close_win, NULL);
			open_images();
			mlx_loop_hook(infos()->mlx, print_player, NULL);
			mlx_loop(infos()->mlx);
		}
	}
	else
		exit_message("Usage: ./so_long [map file]");
}
