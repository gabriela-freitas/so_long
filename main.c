/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 21:37:45 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(void);
void	print_map(int i, int j);

int	key_code(int keycode, void *param)
{
	if (keycode == key_ESC)
	{
		mlx_destroy_window(infos()->mlx, infos()->win_mlx);
		game_over("Thank you for playing");
	}
	if (move_player(keycode))
	{
		ft_printf("steps: %d\n", ++game()->steps);
	}
	return (1);
}

int	print_player(void *param)
{
	char	*str;

	print_map(-1, -1);
	mlx_put_image_to_window(infos()->mlx, infos()->win_mlx,
		img()->player, game()->player.x * PX, game()->player.y * PX);
	str = ft_strjoin("Steps: ", ft_itoa(game()->steps));
	mlx_string_put(infos()->mlx, infos()->win_mlx, 32, 20, 0x00FFFFFF, str);
	free(str);
}

int	close_win(void *param)
{
	mlx_destroy_window(infos()->mlx, infos()->win_mlx);
	game_over("Thank you for playing");
}

int	main(int argc, char **argv)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (argc == 2)
	{
		parse_map(argv[1]);
		infos()->mlx = mlx_init();
		(infos()->win_mlx) = mlx_new_window(infos()->mlx,
				PX * (infos()->width - 1), PX * infos()->height, "so_long");
		mlx_hook(infos()->win_mlx, 2, 1L << 0, key_code, infos());
		mlx_hook(infos()->win_mlx, 17, 1L << 2, close_win, infos());
		open_images();
		mlx_loop_hook(infos()->mlx, print_player, (void *)infos());
		mlx_loop(infos()->mlx);
	}
	else
		exit_message("Usage: ./so_long [map file]");
}
