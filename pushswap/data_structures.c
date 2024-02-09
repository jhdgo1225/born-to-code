/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:47:10 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/21 13:47:11 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(int *a, int *tmp, int start, int end)
{
	int		i;
	int		mid;
	int		idx[3];

	mid = (start + end) / 2;
	idx[0] = start;
	idx[1] = mid;
	idx[2] = start;
	while (idx[0] < mid && idx[1] < end)
	{
		if (a[idx[0]] > a[idx[1]])
			tmp[idx[2]++] = a[idx[1]++];
		else
			tmp[idx[2]++] = a[idx[0]++];
	}
	while (idx[0] < mid)
		tmp[idx[2]++] = a[idx[0]++];
	while (idx[1] < end)
		tmp[idx[2]++] = a[idx[1]++];
	i = start;
	while (i < end)
	{
		a[i] = tmp[i];
		i++;
	}
}

void	merge_sort(int *a, int *tmp, int start, int end)
{
	int	mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		merge_sort(a, tmp, start, mid);
		merge_sort(a, tmp, mid, end);
		merge(a, tmp, start, end);
	}
}

int	binary_search(int *arr, int element, int low, int high)
{
	int	mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < element)
			low = mid + 1;
		else if (arr[mid] > element)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
