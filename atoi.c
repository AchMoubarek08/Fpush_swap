
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	a;
	long	k;

	k = 0;
	a = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' )
	{			
		a = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
		k = k * 10 + str[i] - '0';
		i++;
		}
		else
		{
			ft_putstr("error\n");
			exit(0);
		}
	}
	if(k > (long)2147483647)
	{
		ft_putstr("error\n");
		exit(0);
	}
	return (k * a);
}