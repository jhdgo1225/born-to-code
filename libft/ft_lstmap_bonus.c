/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:29:50 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/16 14:08:48 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*tmp;
	void	*val;

	new_lst = NULL;
	tmp = lst;
	while (tmp != NULL)
	{
		val = f(tmp->content);
		new_node = ft_lstnew(val);
		if (new_node == NULL)
		{
			del(val);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		tmp = tmp->next;
	}
	return (new_lst);
}
