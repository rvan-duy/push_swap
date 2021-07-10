/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_rotate.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:23:16 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 11:14:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"
#include "node.h"

// Rotates a list, the first node becomes the last one
void	operation_rotate(t_node **head, char *msg)
{
	t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = node_unlink(head, *head);
	node_back_add(head, tmp);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}

// Rotates two lists, the first node becomes the last one
void	operation_rotate_both(t_node **head1, t_node **head2, char *msg)
{
	operation_rotate(head1, NULL);
	operation_rotate(head2, NULL);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}
