/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 14:04:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/25 17:22:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdio.h>

void	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	*ps_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		ps_error();
	return (ptr);
}

void	ps_sorted_check(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int32_t	prev_value;

	tmp = *stack_a;
	prev_value = INT32_MIN;
	if (*stack_b)
	{
		ft_putendl_fd("[KO]", 1);
		exit(1);
	}
	while (tmp)
	{
		if (tmp->value < prev_value)
		{
			ft_putendl_fd("[KO]", 1);
			exit(1);
		}
		prev_value = tmp->value;
		tmp = tmp->next;
	}
}

int	ps_atoi(char *s)
{
	int64_t	num;
	int32_t	i;
	int32_t	neg;

	num = 0;
	i = 0;
	neg = 1;
	if (s[0] == '\0' || (s[0] == '-' && !ft_isdigit(s[1])))
		ps_error();
	if (s[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			ps_error();
		num = num * 10 + s[i] - 48;
		if ((neg == -1 && num > 2147483648) || (neg != -1 && num > 2147483647))
			ps_error();
		i++;
	}
	return (neg * num);
}
