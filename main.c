/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:14:38 by frocha-b          #+#    #+#             */
/*   Updated: 2025/07/10 18:21:33 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		split_used;
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], " ");
		split_used = 1;
	}
	if (check_args(argv))
		stack_init(&a, argv + 1);
	else
		return (write(2, "Error\n", 6));
	if (!stack_sorted(&a))
	{
		if(lst_size(&a) <= 5)
			tiny_sort(&a, &b);
		else
			push_swap(&a, &b);
	}
}