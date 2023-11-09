/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:07:09 by nmaturan          #+#    #+#             */
/*   Updated: 2023/11/07 15:12:02 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	newnode(int *content)
{
	t_node	*node;

	node = (void *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content;
}
