/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_push.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:20:35 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 10:51:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "node.h"
#include "libft.h"

// Pushes the head of list dst to list src
void	ps_operation_push(t_node **dst, t_node **src, char *msg)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = ps_node_unlink(src, *src);
	ps_node_front_add(dst, tmp);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}
