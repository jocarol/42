/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:19:37 by jocarol           #+#    #+#             */
/*   Updated: 2016/12/19 19:11:50 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_param(char **str, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		my_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int		my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	char	*tmp;
	int		count;
	int		word;

	count = 1;
	while (count)
	{
		count = 0;
		word = 1;
		while (word < argc - 1)
		{
			if (my_strcmp(argv[word], argv[word + 1]) > 0)
			{
				tmp = argv[word];
				argv[word] = argv[word + 1];
				argv[word + 1] = tmp;
				count++;
			}
			word++;
		}
	}
	print_param(argv, argc);
	return (0);
}
