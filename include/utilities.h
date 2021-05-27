/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 13:16:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"

// split fucked things up
// push_swap operations combined with message

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **stack_a, t_node **stack_b);
int		ps_atoi(char *s);
void	ps_putresult(int result);
void	ps_stack_dup_check(int32_t number, t_node **head);

#endif