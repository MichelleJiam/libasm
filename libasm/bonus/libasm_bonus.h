/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 16:47:35 by mjiam         #+#    #+#                 */
/*   Updated: 2020/07/02 20:01:08 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H
# include <stdio.h>

typedef struct      s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;

int     ft_atoi_base(const char *str, int str_base);
void    ft_list_push_front(t_list **head, void *data);
int     ft_list_size(t_list *head);
void    ft_list_sort(t_list **head, int (*cmp)());
void    ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)());

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
