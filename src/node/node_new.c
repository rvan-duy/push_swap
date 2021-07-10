/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:01:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 10:45:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "libft.h"

t_node	*node_new(int32_t number)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (node == NULL)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Failed to allocate memory.", 2);
		exit(EXIT_FAILURE);
	}
	node->value = number;
	return (node);
}
