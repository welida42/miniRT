/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:07:02 by welida            #+#    #+#             */
/*   Updated: 2021/03/21 19:07:04 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_vector(t_vector vec)
{
	if (vec.x < -1 || vec.x > 1 || vec.y < -1 || vec.y > 1 || vec.z < -1 ||
		vec.z > 1 || (vec.x == 0 && vec.y == 0 && vec.z == 0))
		return (1);
	return (0);
}

int		check_color(t_rgb rgb)
{
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0
	|| rgb.b > 255)
		return (1);
	return (0);
}

int		l_args(char **splitted)
{
	int i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

int		check_symbol(char c)
{
	if (c == ' ' | c == '\n' | c == '.' || c == ',' || (c >= '0' && c <= '9')
		|| c == '-')
		return (1);
	return (0);
}

int		check_line(char **line)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (line[j])
	{
		i = 0;
		while (line[j][i])
		{
			if (!check_symbol(line[j][i]))
				error_exit(-3);
			i++;
		}
		j++;
	}
	return (0);
}
