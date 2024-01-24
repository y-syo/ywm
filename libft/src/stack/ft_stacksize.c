/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:35:55 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 00:39:58 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		i++;
		while (stack->next)
		{
			stack = stack->next;
			i++;
		}
	}
	return (i);
}
