/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:58:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/20 16:30:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include <stdio.h>

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

static void	ps_stack_dup_check(int32_t number, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (number == tmp->value)
			ps_error();
		tmp = tmp->next;
	}
}

// static void	ps_node_sortedstack_add(t_node **head, t_node *new)
// {
// 	t_node	*tmp;

// 	tmp = *head;
// 	if (!tmp || (!tmp->next && new->value > tmp->value))
// 		ps_node_back_add(head, new);
// 	else
// 	{
// 		while (tmp)
// 		{
// 			printf("Hey\n");
// 			if (tmp)
// 			{
// 				printf("*%d %d*\n", tmp->value, new->value);
// 				if (tmp->value < new->value && tmp->next->value > new->value)
// 				{
// 					ft_putendl_fd("[found spot to put it in ;)]", 0);
// 					ps_node_inbetween_add(tmp, tmp->next, new);
// 				}
// 			}
// 			printf("Hey\n");
// 			tmp = tmp->next;
// 		}
// 	}
// 	ft_putendl_fd("[begin]", 0);
// 	ps_node_print(head);
// 	ft_putendl_fd("[end]", 0);
// }

static void	ps_node_sortedstack_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	tmp = *head;
	if (!tmp)
		ps_node_back_add(head, new);
	while (tmp)
	{
		printf("Tmp exists..\n");
		if (tmp && tmp->next)
		{
			printf("Tmp is in the middle.\n");
			if (tmp->value < new->value && tmp->next->value > new->value)
			{
				ft_putendl_fd("[Spot found]", 0);
				ps_node_inbetween_add(tmp, tmp->next, new);
				return ;
			}
		}
		else if (tmp && !tmp->next)
		{
			printf("Is at the end.\n");
			if (tmp->value < new->value)
				ps_node_back_add(head, new);
			else
				ps_node_front_add(head, new);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putendl_fd("[begin]", 0);
	ps_node_print(head);
	ft_putendl_fd("[end]", 0);
}

static void	ps_stack_ab_init(t_data *data, int32_t argc, char **argv)
{
	int32_t	number;

	while (argc > 1)
	{
		number = ps_atoi(argv[argc - 1]);
		if (data->stack_a)
			ps_stack_dup_check(number, &data->stack_a);
		ps_node_front_add(&data->stack_a, ps_node_new(number));
		ps_node_sortedstack_add(&data->sorted, ps_node_new(number));
		argc--;
	}
	printf("stack_a\n");
	ps_node_print(&data->stack_a);
	printf("sorted\n");
	ps_node_print(&data->sorted);
}

void	ps_init(t_data *data, int argc, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	ps_stack_ab_init(data, argc, argv);
	data->total_len = ps_node_len(&data->stack_a);
}
