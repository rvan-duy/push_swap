/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_rev_rotate.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:24:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 11:09:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"

void	operation_rev_rotate(t_node **head, char *msg)
{
	t_node	*tmp_1;
	t_node	*tmp_2;

	if (!*head || !(*head)->next)
		return ;
	tmp_1 = node_get_last(head);
	tmp_2 = node_unlink(head, tmp_1);
	node_front_add(head, tmp_2);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}

void	operation_rev_rotate_both(t_node **head1, t_node **head2, char *msg)
{
	operation_rev_rotate(head1, NULL);
	operation_rev_rotate(head2, NULL);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}
