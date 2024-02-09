/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:22 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 20:22:09 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args_dup(t_deque *queue)
{
	t_deque_node	*ptr1;
	t_deque_node	*ptr2;

	ptr1 = queue->front;
	while (ptr1->right != NULL)
	{
		ptr2 = ptr1->right;
		while (ptr2 != NULL)
		{
			if (ptr1->content == ptr2->content)
			{
				ft_printf("Error\n");
				deque_clear(queue);
				exit(1);
			}
			ptr2 = ptr2->right;
		}
		ptr1 = ptr1->right;
	}
}

t_deque	*convert_to_stack(int *refined, size_t cnt)
{
	t_deque	*deque;
	size_t	i;
	int		check;

	deque = deque_create();
	if (deque == NULL)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		check = deque_push_back(deque, refined[i++]);
		if (check == 0)
		{
			deque_clear(deque);
			return (NULL);
		}
	}
	return (deque);
}

int	*execute_coord_compress(char **strs)
{
	size_t	cnt;
	int		*nums;
	int		*refined;

	cnt = count_word(strs);
	nums = (int *)malloc(sizeof(int) * cnt);
	if (nums == NULL)
		return (NULL);
	if (cvt_integer(nums, strs) == 0)
		return (NULL);
	refined = (int *)malloc(sizeof(int) * cnt);
	if (refined == NULL)
	{
		free(nums);
		return (NULL);
	}
	if (coord_compression(nums, refined, cnt) == 0)
	{
		free(nums);
		free(refined);
		return (NULL);
	}
	free(nums);
	return (refined);
}

char	**start_tokenizing(int argc, char **argv)
{
	char	**strs;
	int		check;
	int		cnt;

	cnt = count_tokens(argc, argv);
	if (cnt == -1)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (strs == NULL)
		return (NULL);
	check = tokenize_args(argc, argv, strs);
	if (check == 0)
		return (NULL);
	return (strs);
}

t_deque	*parse_args(int argc, char **argv)
{
	char	**strs;
	int		*refined;
	int		size;
	t_deque	*qa;

	strs = start_tokenizing(argc, argv);
	if (strs == NULL)
		return (NULL);
	refined = execute_coord_compress(strs);
	if (refined == NULL)
	{
		free_perfectly_on_main(strs);
		return (NULL);
	}
	size = count_word(strs);
	free_perfectly_on_main(strs);
	qa = convert_to_stack(refined, size);
	if (qa == NULL)
	{
		free(refined);
		return (NULL);
	}
	check_args_dup(qa);
	free(refined);
	return (qa);
}
