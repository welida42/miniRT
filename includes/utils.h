/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:19:42 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 10:24:39 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	error_exit(int code);
# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
float	ft_atof(char *str);
void	*ft_memset(void *b, int c, size_t len);

int		l_args(char **splitted);
int		check_vector(t_vector vec);
int		check_color(t_rgb rgb);
int		check_line(char **line);
void	comma_count(char *str, int dot_max, int coma_max, int minus_max);

#endif
