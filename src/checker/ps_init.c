/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:58:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/18 17:42:50 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdint.h>

static int	ps_atoi(char *s)
{
	int64_t	number;
	int32_t	i;
	int32_t	negative;

	number = 0;
	i = 0;
	negative = 1;
	if (s[i] == '-')
	{
		negative = negative * -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			ps_error();
		number = number * 10 + s[i] - 48;
		if (number > INT32_MAX)
			ps_error();
		i++;
	}
	return (negative * number);
}

static void	ps_stack_dup_check(int32_t number, t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (number == tmp->value)
			ps_error();
		tmp = tmp->next;
	}
}

static void	ps_stack_ab_init(t_data *data, int32_t argc, char **argv)
{
	int32_t	number;

	while (argc > 1)
	{
		number = ps_atoi(argv[argc - 1]);
		if (data->stack_a)
			ps_stack_dup_check(number, &data->stack_a);
		ps_stack_front_add(&data->stack_a, ps_stack_new(number));
		argc--;
	}
	ps_stack_print(&data->stack_a);
}

void	ps_init(t_data *data, int argc, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	ps_stack_ab_init(data, argc, argv);
}
