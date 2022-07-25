/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 23:29:46 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(void);
void	print_map(int i, int j);

int	key_code(int keycode, void *param)
{
	(t_so_long *)param;
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
	char *str;

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
	game()->steps = 0;
	game()->collects = 0;
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
			else if (infos()->map[i][j] == 'E')
				mlx_put_image_to_window(infos()->mlx,
					infos()->win_mlx, img()->exit, PX * j, PX * i);
			else if (infos()->map[i][j] == 'C')
				mlx_put_image_to_window(infos()->mlx,
					infos()->win_mlx, img()->collect, PX * j, PX * i);
			else
				mlx_put_image_to_window(infos()->mlx,
					infos()->win_mlx, img()->empty, PX * j, PX * i);
		}
	}
}
