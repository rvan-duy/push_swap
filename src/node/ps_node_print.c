/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:04:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/28 17:57:26 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"

static int32_t	binary_conversion(int32_t num)
{
	if (num == 0)
		return (0);
	else
		return ((num % 2) + 10 * binary_conversion(num / 2));
}

// Prints out the stack from head until the end
void	ps_node_print(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ft_putstr_fd("index[", 0);
		ft_putnbr_fd(tmp->index, 0);
		ft_putstr_fd("] ", 0);
		ft_putnbr_fd(tmp->value, 0);
		ft_putstr_fd(" (", 0);
		ft_putnbr_fd(binary_conversion(tmp->index), 0);
		ft_putstr_fd(")", 0);
		ft_putchar_fd('\n', 0);
		tmp = tmp->next;
	}
}
