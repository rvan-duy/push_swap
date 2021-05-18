/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 15:57:36 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/18 17:39:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

// Prints out the stack from head until the end
void	ps_stack_print(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 0);
		printf("\t%p\n", tmp);
		ft_putchar_fd('\n', 0);
		tmp = tmp->next;
	}
}

t_node	*ps_stack_last_get(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

// Adds a node to the front of a list
void	ps_stack_front_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	tmp->prev = new;
	new->next = *head;
	*head = new;
}

// Adds a node to the back of a list
void	ps_stack_back_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	tmp = ps_stack_last_get(head);
	tmp->next = new;
	new->prev = tmp;
}

// Creates new node
t_node	*ps_stack_new(int32_t number)
{
	t_node	*node;

	node = ps_calloc(sizeof(t_node));
	node->value = number;
	return (node);
}

// Unlinks node from a list
t_node	*ps_stack_unlink(t_node	**head, t_node *node)
{
	if (!node->prev && node->next)
	{
		*head = node->next;
		(*head)->prev = NULL;
	}
	else if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else if (node->prev && !node->next)
		node->prev->next = NULL;
	else
		*head = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
