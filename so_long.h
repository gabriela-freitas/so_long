/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:54:16 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/20 21:52:06 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_so_long
{
	char	**map;
	int		width;
	int		height;
}	t_so_long;

t_so_long	*infos(void);
void		exit_message(char *error);
void		parse_map(char *file_name);

#endif
