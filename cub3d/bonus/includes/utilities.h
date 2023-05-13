/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:48:11 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 08:33:39 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_malloc.h"
# include "queue.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_error(const char *str);
void	ft_error_exit(const char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_arrlen(char **arr);
int		int_check(char *str);
int		ft_in(char c, const char *str);

char	*get_next_line(int fd);
char	**msk_split(char const *s, int (*f)(char c));
char	*ft_strtrim(char const *s1, char const *set);
void	ft_str_replace(char *str, char c, char by);
char	*ft_itoa(int n);
int		max(int a, int b);
int		min(int a, int b);

#endif
