/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_and_read_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:30:21 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:30:28 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	check_input_exceptions(int ac, char **av)
{

	if (ac == 2 || ac == 1)
	{
		if ((!av[1][0])
			|| (count_char_into_string(av[1], ' ') == ft_strlen(av[1]))
			|| ft_isascii(av[1][0]) < 48 || ft_isascii(av[1][0]) > 57
			|| ac == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
}

int		check_args(int ac, char **av)
{
	int		i;
	int		j;
	int		count_repeats;
	char	*str;

	i = 0;
	count_repeats = 0;
	while (i++ < ac - 1)
	{
		str = ft_itoa(ft_atoi(av[i]));
		if (!(ft_strequ(av[i], str)))
//			|| ft_isascii(av[i][0]) < 48 || ft_isascii(av[i][0]) > 57)
			return (-1);
		free(str);
		j = 0;
		while (j++ < ac - 1)
		{
			if (ft_strequ(av[i], av[j]))
				count_repeats++;
		}
	}
	if (count_repeats > ac)
		return (-1);
	else
		return (0);
}

void	check_input_error(int ac, char **av)
{
	if (ac == 1)
	{
		if (ft_isalpha(av[0][0]))
			ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_args(ac, av) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int		count_char_into_string(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	read_input_chain(int ac, char **av, t_stack *chain, int not_str)
{
	int		i;
	t_node	*node;

	i = not_str;
	while ((i < ac) && ((av[i][0] != '\n')))
	{
		node = create_node(ft_atoi(av[i]));
		if (chain->down == NULL)
			chain->down = node;
		node->prev = chain->down;
		node->next = NULL;
		if (chain->down)
			chain->down->next = node;
		chain->down = node;
		if (chain->top == NULL)
			chain->top = node;
		chain->size++;
		i++;
	}
	chain->top->prev = NULL;
}