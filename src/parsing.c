/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:35:08 by efranco           #+#    #+#             */
/*   Updated: 2025/04/24 12:12:58 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_one_arg(char *arg)
{
	int		i;
	long	number;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
		{
			printf("Not a digit argument\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = ft_atol(arg);
	if (number <= 0)
	{
		printf("Error: Below 1\n");
		exit(EXIT_FAILURE);
	}
	if (number > INT_MAX)
	{
		printf("Error: Above INT_MAX\n");
		exit(EXIT_FAILURE);
	}
}
void	check_special(char *str, int count)
{
	int	num;

	num = ft_atoi(str);
	if (count == 1 || count == 5)
		return ;
	else if(num < 60)
	{
		printf("< 60\n");
		exit(EXIT_FAILURE);
	}
}
void parse_line(char **line, int count)
{
	int	i;

	i = 1;
	while (i < count)
	{
		check_one_arg(line[i]);
		check_special(line[i], i);
		i++;
	}
}
