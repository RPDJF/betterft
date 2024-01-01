/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:13 by rude-jes          #+#    #+#             */
/*   Updated: 2024/01/01 02:49:25 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

t_garbcol	**getgarbage(void)
{
	static t_garbcol	**collector;

	if (!collector)
	{
		collector = (t_garbcol **)malloc(sizeof(t_garbcol *));
		*collector = 0;
	}
	return (collector);
}

int	gfree(void *address)
{
	t_garbcol	**collector;
	t_garbcol	*todel;

	collector = getgarbage();
	if (!collector)
		return (-1);
	todel = *collector;
	while (todel && todel->content != address)
		todel = todel->next;
	if (!todel)
		free(address);
	else
	{
		if (todel->previous)
			todel->previous->next = todel->next;
		else if (todel->next)
			*collector = todel->next;
		else
			*collector = 0;
		free(todel->content);
		free(todel);
	}
	return (0);
}

void	*addgarbage(void *address)
{
	t_garbcol	**collector;
	t_garbcol	*tmp;
	t_garbcol	*last;

	collector = getgarbage();
	if (!collector)
		return (0);
	tmp = (t_garbcol *)malloc(sizeof(t_garbcol));
	if (!tmp)
		return (0);
	last = 0;
	tmp->next = 0;
	tmp->previous = 0;
	tmp->content = address;
	if (*collector)
	{
		last = lastgarbage(*collector);
		last->next = tmp;
		tmp->previous = last;
	}
	else
		*collector = tmp;
	return (tmp->content);
}

void	*galloc(size_t size)
{
	return (addgarbage(malloc(size)));
}

void	cleargarbage(void)
{
	t_garbcol	**collector;
	t_garbcol	*todel;
	t_garbcol	*tmp;

	collector = getgarbage();
	todel = *collector;
	while (todel)
	{
		free(todel->content);
		tmp = todel->next;
		free(todel);
		todel = tmp;
	}
	free(collector);
}
