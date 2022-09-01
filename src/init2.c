/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:59 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:49 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_img(t_img *img)
{
	img->ptr = 0;
	img->width = 0;
	img->height = 0;
	img->addr = 0;
	img->bpp = 0;
	img->line_size = 0;
	img->endian = 0;
}

void	init_assets(t_assets *assets)
{
	init_img(&(assets->no));
	init_img(&(assets->so));
	init_img(&(assets->we));
	init_img(&(assets->ea));
	assets->f[0] = -1;
	assets->c[0] = -1;
	assets->f[1] = -1;
	assets->c[1] = -1;
	assets->f[2] = -1;
	assets->c[2] = -1;
}
