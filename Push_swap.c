/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:38:33 by amoubare          #+#    #+#             */
/*   Updated: 2022/03/06 22:39:28 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pile	sorttree(pile st)
{
	int	top;
	int	middle;
	int	bottom;

	top = st->i;
	middle = st->next->i;
	bottom = st->next->next->i;
	if (top > middle && middle < bottom && top < bottom)
		swap_stack(st, "sa\n");
	else if (top > middle && middle > bottom)
	{
		rotate_stack(st, "ra\n");
		swap_stack(st, "sa\n");
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_stack(st, "ra\n");
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_stack(st, "sa\n");
		rotate_stack(st, "ra\n");
	}
	else if (top < middle && middle > bottom && top > bottom)
	{
		rotate_stack(st, "ra\n");
		rotate_stack(st, "ra\n");
	}
	return (st);
}

void	sortfour(pile *a, pile *b)
{
	*a = prep_four(*a);
	push_to_stack(a, b, "pb\n");
	*a = sorttree(*a);
	push_to_stack(b, a, "pa\n");
}

void	sortfive(pile *a, pile *b)
{
	*a = prep_five(*a);
	push_to_stack(a, b, "pb\n");
	sortfour(a, b);
	push_to_stack(b, a, "pa\n");
}

int	main(int argc, char **argv)
{
	pile a = new_pile();
	pile b = new_pile();
	int i = argc;
	int *p;
	pile cp;

    p = (int *)malloc(24);
    
    while (i > 1)
    {
        a = push_stack(a,ft_atoi(argv[i - 1]));
        i--;
    }
    check_dup(a);
    is_sorted(a,argc);
    if(argc == 4)
        a = sorttree(a);
    else if(argc == 5)
        sortfour(&a, &b);
    else if(argc == 6)
        sortfive(&a, &b);
    else if(argc > 6 && argc < 30)
    {
        insertionsortt(&a, &b, argc);
        push_back_to_a(&a, &b, argc - 1, 1);
    }
    else
    {
        i = 0;
        p[0] = getminelem(a) - 1;
        getcunk(cp, argc, p, argv);
        push_chunks_to_b(&a, &b, argv, p, argc);
        push_chunks_to_b(&a, &b, argv, p, argc);
        push_chunks_to_b(&a, &b, argv, p, argc);
        insertionsortt(&a, &b, argc);
        push_back_to_a(&a, &b, argc - 1, 4);
        pushmax(&a, &b, argc);
    }
    print_stack(a);
    printf("----------\n");
    print_stack(b);
    return(0);
}

// int main(int argc, char **arv)
// {
//     pile a = new_pile();
//     pile b = new_pile();
//     int i = 99, j = 1;
//     int ko[100] = {792,596,556,677,754,816,-448,648,-237,408,963,29,680,516,820,947,376,668,717,508,-138,917,-219,941,-742,632,-301,-386,553,-758,439,-10,465,-326,-348,198,-771,270,-533,-145,-74,-197,66,-638,161,-164,429,-945,-939,-228,-279,834,527,736,-491,355,-675,-287,-970,-657,332,983,353,-231,142,-839,-224,507,870,-958,-548,-713,-143,794,54,-915,104,493,101,-15,-101,-768,-528,226,-523,534,-527,838,286,-293,225,-705,-959,656,-171,-303,-954,-764,-136,-621};


//     while (i >= 0)
//     {
//         a = push_stack(a,ko[i]);
//         i--;
//     }
//     while(j <= argc-1)
//     {
//         if (!strcmp(arv[j], "pa"))
//         {
//             push_to_stack(&b,&a,"pa ");
//         }
//         if (!strcmp(arv[j], "pb"))
//         {
//             push_to_stack(&a,&b,"pb ");
//         }
//         if (!strcmp(arv[j], "ra"))
//         {
//             a = rotate_stack(a, "ra ");
//         }
//         if (!strcmp(arv[j], "rb"))
//         {
//             b = rotate_stack(b, "rb ");
//         }
//         if (!strcmp(arv[j], "rra"))
//         {
//             reverse_rotate(&a,"rra ");
//         }
//         if (!strcmp(arv[j], "rrb"))
//         {
//             reverse_rotate(&b,"rrb ");
//         }
//         j++;
//     }
//     print_stack(a);
//     printf("sqc\n");
//     print_stack(b);
// }
