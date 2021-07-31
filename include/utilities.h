/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/31 20:30:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"

# define OK 1
# define KO 0

# include <stdint.h>

void	init(t_data *data, int argc, char **argv);
void	*ps_calloc(size_t size);
void	error(void);
void	sorted_check(t_node **stack_a, t_node **stack_b);
void	putresult(int result);
void	stack_dup_check(int number, t_node **head);
int	    ps_atoi(char *s);
void	free_list(t_node *head);

#endif