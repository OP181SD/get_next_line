/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:04:57 by yasaidi           #+#    #+#             */
/*   Updated: 2022/12/26 20:51:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static	int	sub_len(const char *s, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*tab;
	unsigned int		i;
	unsigned int		j;
	unsigned int		s_len;

	if (start >= (unsigned int)ft_strlen(s))
		return (NULL);
	s_len = sub_len(s, (size_t)start, len);
	tab = (char *)malloc(s_len + 1 * sizeof(char));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (s[start + i] && j < len)
	{
		tab[j] = s[i + start];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

int	ft_strchr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
