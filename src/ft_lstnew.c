/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:25:04 by rude-jes          #+#    #+#             */
/*   Updated: 2024/01/21 02:04:17 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)galloc(sizeof(t_list));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	p->prev = 0;
	return (p);
}
