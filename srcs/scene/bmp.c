/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:36:33 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 13:36:36 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	header(unsigned char *header, t_scene *scene)
{
	unsigned int pixels_x;
	unsigned int zeroes;

	(void)scene;
	ft_memset(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	pixels_x = scene->width * 3;
	zeroes = (4 - (pixels_x % 4)) % 4;
	header[2] = 54 + scene->height * (pixels_x + zeroes);
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 24;
	header[18] = (unsigned char)(scene->width);
	header[19] = (unsigned char)(scene->width >> 8);
	header[20] = (unsigned char)(scene->width >> 16);
	header[21] = (unsigned char)(scene->width >> 24);
	header[22] = (unsigned char)(scene->height);
	header[23] = (unsigned char)(scene->height >> 8);
	header[24] = (unsigned char)(scene->height >> 16);
	header[25] = (unsigned char)(scene->height >> 24);
}

void	free_buffer(t_rgb3 **buffer, unsigned int height)
{
	unsigned int i;

	i = 0;
	while (i < height)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

void	bmp_write(t_scene *scene, t_rgb3 **pixels, int fd)
{
	unsigned int	pixels_x;
	unsigned int	zero3;
	unsigned char	zeroes[3];
	int				line;

	ft_memset(zeroes, 0, 3);
	pixels_x = scene->width * 3;
	zero3 = (4 - (pixels_x % 4)) % 4;
	line = (int)scene->height;
	while (line >= 0)
	{
		write(fd, pixels[line], pixels_x);
		write(fd, zeroes, zero3);
		line--;
	}
}

t_rgb3	**create_buffer(unsigned int height, unsigned int width)
{
	t_rgb3			**buffer;
	unsigned int	i;

	i = 0;
	buffer = malloc(sizeof(t_rgb3 *) * height);
	while (i < height)
	{
		buffer[i] = malloc(sizeof(t_rgb3) * width);
		i++;
	}
	return (buffer);
}

void	save_bmp(t_scene *scene)
{
	int				fd;
	unsigned char	header_buf[54];
	t_rgb3			**buffer;

	header(header_buf, scene);
	fd = open("minirt.bmp", O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0777);
	buffer = create_buffer(scene->height, scene->width);
	ray_tracing_bmp(buffer, scene, scene->cameras);
	write(fd, header_buf, 54);
	bmp_write(scene, buffer, fd);
	free_buffer(buffer, scene->height);
	close(fd);
}
