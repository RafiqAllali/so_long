/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:53:10 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:32:45 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*str;

	l = ft_strlen(s1);
	i = 0;
	str = malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char *str1)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (ft_strdup(str1));
	while (str[i])
		i++;
	while (str1[j])
		j++;
	s = malloc((i + j + 1) * sizeof(char));
	if (!s)
		return (free(str), free(str1), NULL);
	i = -1;
	while (str[++i])
		s[i] = str[i];
	j = -1;
	while (str1[++j])
		s[i + j] = str1[j];
	s[i + j] = '\0';
	return (free(str), s);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}
