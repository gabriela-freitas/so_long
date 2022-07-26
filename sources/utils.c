/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:26:53 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 23:06:41 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(void)
{
	free_split(infos()->map);
	mlx_destroy_image(infos()->mlx, img()->collect);
	mlx_destroy_image(infos()->mlx, img()->empty);
	mlx_destroy_image(infos()->mlx, img()->enemy);
	mlx_destroy_image(infos()->mlx, img()->exit);
	mlx_destroy_image(infos()->mlx, img()->wall);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_a[0]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_a[1]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_s[0]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_s[1]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_w[0]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_w[1]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_d[0]);
	mlx_destroy_image(infos()->mlx, img()->play_mv.player_d[1]);
	free(infos()->mlx);
}

void	exit_message(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	free_split(infos()->map);
	exit(EXIT_FAILURE);
}

void	game_over(char *message)
{
	mlx_destroy_window(infos()->mlx, infos()->win_mlx);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	free_so_long();
	exit(EXIT_SUCCESS);
}
