/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:34 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:52 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/deque/deque.h"
# include "libft/libft/libft.h"
# include "libft/ft_printf_project/ft_printf.h"

int		binary_search(int *arr, int element, int low, int high);
void	merge_sort(int *a, int *tmp, int start, int end);
void	merge(int *a, int *tmp, int start, int end);
t_deque	*parse_args(int argc, char **argv);
void	free_perfectly_on_main(char **words);
size_t	count_word(char **strs);
int		check_integer(const char *str);
int		count_tokens(int argc, char **argv);
int		tokenize_args(int argc, char **argv, char **strs);
int		cvt_integer(int *nums, char **strs);
int		coord_compression(int *origin, int *res, size_t cnt);
void	hard_sorting_a(t_deque *qa, t_deque *qb, int start, int end);
void	hard_sorting_three_a(t_deque *qa, t_deque *qb, int end);
void	hard_sorting_three_a_special(t_deque *qa);
void	hard_sorting_b(t_deque *qb, t_deque *qa, int start, int end);
void	hard_sorting_three_b(t_deque *qb, t_deque *qa, int end);
void	push_swap_up_a(t_deque *qa, t_deque *qb, int start, int end);
void	push_swap_down_a(t_deque *qa, t_deque *qb, int start, int end);
void	push_swap_up_b(t_deque *qb, t_deque *qa, int start, int end);
void	push_swap_down_b(t_deque *qb, t_deque *qa, int start, int end);
void	execute_cmd_a(t_deque *qa, t_deque *qb, int start, int end);
void	execute_cmd_a_eq_size(t_deque *qa, t_deque *qb, int start, int end);
void	execute_cmd_b(t_deque *qb, t_deque *qa, int start, int end);
void	execute_cmd_b_eq_size(t_deque *qb, t_deque *qa, int start, int end);
int		check_ascend_sort(t_deque *qa, int start, int end);
int		check_descend_sort(t_deque *qb, int start, int end);
void	high_a(t_deque *qa);
void	mid_a(t_deque *qa, t_deque *qb);
void	low_a(t_deque *qb);
void	high_b(t_deque *qb, t_deque *qa);
void	mid_b(t_deque *qa);
void	low_b(t_deque *qb);
void	concorrent_rotate_a(t_deque *qa, t_deque *qb);
void	concorrent_rotate_b(t_deque *qb, t_deque *qa);

#endif
