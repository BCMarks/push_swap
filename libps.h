/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:09:59 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:15:51 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# define SORT_SIZE 21
# define SORT_SIZE2 60

void	operations(char *cmd, char **stack_a, char **stack_b, int size[]);
void	push_stack(char **give, char **get, int *sz_give, int *sz_get);
void	rot_stack(char **stack, int *size);
void	revrot_stack(char **stack, int *size);

int		checka(char **stack_a, char **stack_b, int size);
void	stack_init(char **stack_a, char **stack_b, char **list, int size);
void	disp_lists(char **stack1, char **stack2, int size_a, int size_b);
void	arg_format(int n, char **arg, int *num, char **list);

void	c_operations(char *cmd, char **stack_a, char **stack_b, int size[]);

int		c_checka(char **stack_a, char **stack_b, int size);
void	c_stack_init(char **stack_a, char **stack_b, char **list, int size);
void	c_disp_lists(char **stack1, char **stack2, int size_a, int size_b);

void	comparitive(char **stack_a, char **stack_b, int size[]);
void	comparitive2(char **stack_a, char **stack_b, int size[]);
void	brute_solve(char **stack_a, char **stack_b, int size[]);
void	eksaqte(int num, char **stack_a, char **stack_b, int size[]);
void	end_topa(char **stack_a, char **stack_b, int size[]);
void	end_topb(char **stack_a, char **stack_b, int size[]);
void	end_bot(char **stack_a, char **stack_b, int size[]);
int		num_order(int size, char **stack);
int		core_logic(char **stack_a, char **stack_b, int size[]);
void	big_solve1(char **stack_a, char **stack_b, int size[], int n);
void	big_solve2(char **stack_a, char **stack_b, int size[], int n);
void	small_solve(char **stack_a, char **stack_b, int size[]);
void	solve3(char **stack_a, char **stack_b, int size[]);

void	error_snake(void);
void	c_error_snake(void);

#endif
