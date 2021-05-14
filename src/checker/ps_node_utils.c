/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 15:57:36 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/14 18:34:51 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	ps_stack_print(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		ft_putnbr_fd(tmp->value, 0);
		ft_putchar_fd('\n', 0);
		tmp = tmp->next;
	}
}

t_node	*ps_stack_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ps_stack_front_add(t_node **stack, t_node *new)
{
	t_node	*tmp;

	tmp = *stack;
	tmp->prev = new;
	new->next = *stack;
	*stack = new;
}

t_node	*ps_stack_new(int32_t number)
{
	t_node	*node;

	node = ps_calloc(node, sizeof(t_node));
	node->value = number;
	return (node);
}
