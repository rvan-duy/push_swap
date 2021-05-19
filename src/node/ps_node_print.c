/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:04:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 16:04:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"

// Prints out the stack from head until the end
void	ps_node_print(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 0);
		ft_putchar_fd('\n', 0);
		tmp = tmp->next;
	}
}
