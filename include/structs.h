/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:46:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 10:11:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include <stdlib.h>

typedef struct s_node {
	struct s_node	*prev;
	int32_t			value;
	size_t			index;
	struct s_node	*next;
}	t_node;

typedef struct s_data {
	size_t	total_len;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*sorted;
}	t_data;

#endif