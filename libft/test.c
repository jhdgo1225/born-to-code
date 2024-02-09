#include <stdlib.h>
#include <stdio.h>

void	free_perfectly(char **words, size_t word_cnt)
{
	size_t	i;

	i = 0;
	while (i < word_cnt)
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
}

char	*make_word(int *s_idx, char const *s, char c)
{
	char	*word;
	size_t	tmp_idx;
	size_t	word_len;

	word_len = 0;
	tmp_idx = *s_idx;
	while (s[tmp_idx] != '\0' && s[tmp_idx] != c)
	{
		word_len++;
		tmp_idx++;
	}
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	tmp_idx = 0;
	while (s[*s_idx] != '\0' && s[*s_idx] != c)
	{
		word[tmp_idx] = s[*s_idx];
		tmp_idx++;
		(*s_idx)++;
	}
	word[tmp_idx] = 0;
	return (word);
}

int	split_words(char **words, char const *s, char c, int word_cnt)
{
	char	*wd;
	int		word_idx;
	int		s_idx;

	word_idx = 0;
	s_idx = 0;
	while (word_idx < word_cnt)
	{
		while (s[s_idx] == c)
			s_idx++;
		wd = make_word(&s_idx, s, c);
		if (wd == NULL)
		{
			free_perfectly(words, word_idx);
			return (0);
		}
		words[word_idx] = wd;
		word_idx++;
	}
	words[word_idx] = NULL;
	return (1);
}

int	count_words_in_str(char const *s, char c)
{
	size_t	i;
	size_t	word_cnt;
	int		flag;

	i = 0;
	word_cnt = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c) && !flag)
		{
			word_cnt++;
			flag = 1;
		}
		else if (s[i] == c && flag)
			flag = 0;
		i++;
	}
	return (word_cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_cnt;
	int		check;

	word_cnt = count_words_in_str(s, c);
	words = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (words == NULL)
		return (NULL);
	check = split_words(words, s, c, word_cnt);
	if (check == 0)
		return (NULL);
	return (words);
}

int main(void)
{
	char **str;
	int i;

	str = ft_split("hello!", ' ');
	for (i = 0; str[i] != NULL; i++)
		printf("%s\n", str[i]);
	free_perfectly(str, i);
	return (0);
}
