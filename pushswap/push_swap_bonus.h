/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:29:03 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:09:48 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "./libft/libft/libft.h"
# include "./libft/ft_printf_project/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
# include "./libft/deque/deque.h"

void	merge(int *a, int *tmp, int start, int end);
void	merge_sort(int *a, int *tmp, int start, int end);
int		binary_search(int *arr, int element, int low, int high);
t_deque	*parse_args(int argc, char **argv);
int		*copy_array(int *origin, size_t cnt);
int		coord_compression(int *origin, int *res, size_t cnt);
int		check_integer(const char *str);
int		cvt_integer(int *nums, char **strs);
t_deque	*convert_to_stack(int *refined, size_t cnt);
void	free_perfectly_on_main(char **words);
size_t	count_word(char **strs);
int		count_tokens(int argc, char **argv);
int		tokenize_args(int argc, char **argv, char **strs);
int		cmd_processors(t_deque *qa, t_deque *qb);

#endif
