/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 19:49:24 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(void);
void	print_map(int i, int j);

int	key_code(int keycode, void *param)
{
	(t_so_long *)param;
	ft_printf("key: %d\n", keycode);
	if (keycode == key_ESC)
	{
		mlx_destroy_window(infos()->mlx, infos()->win_mlx);
		game_over("Thank you for playing");
	}
	move_player(keycode);
	return (1);
}

int	print_player(void *param)
{
	print_map(-1, -1);
	// if (infos()->player.move)
	// {
	// 	infos()->player.move = 0;
		mlx_put_image_to_window(infos()->mlx, infos()->win_mlx,
			img()->player, infos()->player.x * PX, infos()->player.y * PX);
	// }
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
		open_images();
		mlx_loop_hook(infos()->mlx, print_player, (void *)infos());
		mlx_loop(infos()->mlx);
	}
	else
		exit_message("Usage: ./so_long [map file]");
}

void	open_images(void)
{
	int	img_width;
	int	img_height;

	img_height = PX;
	img_width = PX;
	(img()->collect) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/collectable.xpm", &img_width, &img_height);
	(img()->empty) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/empty.xpm", &img_width, &img_height);
	(img()->exit) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/exit.xpm", &img_width, &img_height);
	(img()->player) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player.xpm", &img_width, &img_height);
	(img()->wall) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/wall.xpm", &img_width, &img_height);
	infos()->player.move = 1;
}

void	print_map(int i, int j)
{
	while (++i < infos()->height)
	{
		j = -1;
		while (++j < (infos()->width - 1))
		{
			if (infos()->map[i][j] == '1')
				mlx_put_image_to_window(infos()->mlx,
					infos()->win_mlx, img()->wall, PX * j, PX * i);
			else
				mlx_put_image_to_window(infos()->mlx,
					infos()->win_mlx, img()->empty, PX * j, PX * i);
		}
	}
}
