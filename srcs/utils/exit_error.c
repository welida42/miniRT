/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:19:27 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 10:27:07 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO,
		"Error, Can't allocate memory for new element\n", 46);
	else if (code == -2)
		write(STDERR_FILENO, "Error, Invalid count of arguments\n", 35);
	else if (code == -5)
		write(STDERR_FILENO, "Error, Invalid arguments name\n", 31);
	else if (code == -3)
		write(STDERR_FILENO, "Error, Invalid scene configuration\n", 36);
	else if (code == -4)
		write(STDERR_FILENO, "Error, Invalid file\n", 21);
	exit(code);
}
