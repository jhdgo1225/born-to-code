/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devpark <devpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:56:20 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/30 00:16:39 by devpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<limits.h>
# include	<unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	free_perfectly(char **words, size_t word_cnt);

#endif
