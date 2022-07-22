/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/22 16:10:59 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(void);
void	print_map(int i, int j);

int	key_code(int keycode, void *param)
{
	(t_so_long *)param;

	ft_printf("key: %d\n", keycode);
	return (1);
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
		(infos()->win_mlx) = mlx_new_window(infos()->mlx, 64 * infos()->width,
				64 * infos()->height, "so_long");
		mlx_hook(infos()->win_mlx, 2, 1L << 0, key_code, infos());
		open_images();
		print_map(-1, -1);
		mlx_loop(infos()->mlx);
	}
	else
		exit_message("Usage: ./so_long [map file]");
}

void	open_images(void)
{
	int	img_width;
	int	img_height;

	img_height = PIXEL;
	img_width = PIXEL;
	(img()->collect) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/collect.xpm", &img_width, &img_height);
	(img()->empty) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/empty.xpm", &img_width, &img_height);
	(img()->exit) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/exit.xpm", &img_width, &img_height);
	(img()->player) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/player.xpm", &img_width, &img_height);
	(img()->wall) = mlx_xpm_file_to_image(infos()->mlx,
			"./images/wall.xpm", &img_width, &img_height);
}

void	print_map(int i, int j)
{
	void	*image;

	while (++i < infos()->height)
	{
		j = -1;
		while (++j < (infos()->width - 1))
		{
			if (infos()->map[i][j] == 'C')
				image = img()->collect;
			if (infos()->map[i][j] == 'E')
				image = img()->exit;
			if (infos()->map[i][j] == 'P')
				image = img()->player;
			if (infos()->map[i][j] == '1')
				image = img()->wall;
			if (infos()->map[i][j] == '0')
				image = img()->empty;
			mlx_put_image_to_window(infos()->mlx, infos()->win_mlx, image, PIXEL * j, PIXEL * i);
		}
		printf("\n");
	}
}
