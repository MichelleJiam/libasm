/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 16:47:35 by mjiam         #+#    #+#                 */
/*   Updated: 2020/11/11 16:58:28 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TURQ "\033[38;5;37m"
# define RED "\033[31m"
# define RES "\033[0m"
# define WHITE "\033[38;5;15m"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

/* bonus tests */
int		bonus(char *av);

/* bonuses */
int		ft_atoi_base(const char *str, int str_base);
char	*ft_strchr(const char *str, int c);

/*
** ft_atoi_base:
** converts the string argument str (base N <= 16) to an int (base 10).
**
** ft_list_push_front:
** adds a new element of type t_list to the beginning of the list.
**
** ft_list_size:
** returns the number of elements in the list.
**
** ft_list_sort:
** sorts the list’s contents by ascending order by comparing two links
** thanks to a function that can compare the data held in those two links.
**
** ft_list_remove_if:
** erases all elements in the list whose data is "equal" to the reference data.
*/

#endif
