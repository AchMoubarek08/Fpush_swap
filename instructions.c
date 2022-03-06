/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:41:13 by amoubare          #+#    #+#             */
/*   Updated: 2022/03/06 22:47:16 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pile	swap_stack(pile st, char *str)
{
	if (st->i && st->next)
	{
		swap(&st->i, &st->next->i);
		ft_putstr(str);
	}
	return (st);
}

pile	rotate_stack(pile st, char *str)
{
	pile	temp;

	temp = st;
	while (temp != NULL && temp->next != NULL)
	{
		swap(&temp->next->i, &temp->i);
		temp = temp->next;
	}
	ft_putstr(str);
	return (st);
}

void	push_to_stack(pile *a, pile *b, char *str)
{
	int	temp;

	temp = (*a)->i;
	*a = pop_stack(*a);
	*b = push_stack(*b, temp);
	ft_putstr(str);
}

pile	prep_four(pile a)
{
	int	top;
	int	two;
	int	three;
	int	four;

	top = a->i;
	two = a->next->i;
	three = a->next->next->i;
	four = a->next->next->next->i;
	if (top > two && two < three && two < four)
		a = rotate_stack(a, "ra\n");
	else if (three < top && three < two && three < four)
	{
		a = rotate_stack(a, "ra\n");
		a = rotate_stack(a, "ra\n");
	}
	else if (four < top && four < two && four < three)
	{
		reverse_rotate(&a, "rra\n");
	}
	return (a);
}

pile	prep_five(pile a)
{
	int	top;
	int	two;
	int	three;
	int	four;
	int	five;

	top = a->i;
	two = a->next->i;
	three = a->next->next->i;
	four = a->next->next->next->i;
	five = a->next->next->next->next->i;
	if (top > two && two < three && two < four && two < five)
	a = rotate_stack(a, "ra\n");
	else if (three < top && three < two && three < four && three < five)
	{
		a = rotate_stack(a, "ra\n");
		a = rotate_stack(a, "ra\n");
	}
	else if (four < top && four < two && four < three && four < five)
	{
		reverse_rotate(&a, "rra\n");
		reverse_rotate(&a, "rra\n");
	}
	else if (five < top && five < two && five < three && five < four)
	{
		reverse_rotate(&a, "rra\n");
	}
	return (a);
}
