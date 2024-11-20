/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_cord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:21:57 by karai             #+#    #+#             */
/*   Updated: 2024/11/20 21:56:36 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	ft_is_duplicate(int *array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (array[i] == array[i + 1])
		{
			printf("Error\n");
			return (true);
		}
		i += 1;
	}
	return (false);
}

void	ft_sort_upper(int *array, int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j += 1;
		}
		i += 1;
	}
}

int	*ft_comp_cord(int *array, int length)
{
	int	*temp_array;
	int	i;
	int	j;

	ft_sort_upper(array, length);
	if (ft_is_duplicate(array, length))
		return (NULL);
	temp_array = (int *)malloc(sizeof(int) * length);
	if (temp_array == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		temp_array[i] = array[i];
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
			if (temp_array[j++] == array[i])
				break ;
		array[i++] = j;
	}
	free(temp_array);
	return (array);
}
