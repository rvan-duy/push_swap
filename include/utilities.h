/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 12:52:12 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"

# define OK 1
# define KO 0

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **stack_a, t_node **stack_b);
void	ps_putresult(int result);
void	ps_stack_dup_check(int32_t number, t_node **head);
int32_t	ps_atoi(char *s);

#endif