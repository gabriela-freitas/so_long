/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:53:50 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/21 14:58:29 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win_mlx;

	//check if the file is .ber
	if (argc == 2)
		parse_map(argv[1]);
	// mlx = mlx_init();
	// win_mlx = mlx_new_window(mlx, 500, 500, "testing");
	// mlx_loop(mlx);
}
