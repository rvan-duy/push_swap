/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_switch.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:22:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 13:22:48 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// Switches first elemements of the stack, does nothing
// if there are only 1 or 0 elements in the stack
void	ps_operation_switch(t_node **head)
{
	t_node	*tmp_1;
	t_node	*tmp_2;

	if (!*head || !(*head)->next)
		return ;
	tmp_1 = *head;
	tmp_2 = tmp_1->next;
	ps_ints_swap(&tmp_1->value, &tmp_2->value);
}

// Switches the first elements of two stacks, does nothing
// if there are only 1 or 0 elements in the stack
void	ps_operation_switch_both(t_node **head1, t_node **head2)
{
	ps_operation_switch(head1);
	ps_operation_switch(head2);
}
