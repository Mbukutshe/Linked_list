/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmbukuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:10:06 by kmbukuts          #+#    #+#             */
/*   Updated: 2019/06/25 17:09:15 by kmbukuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "linked_list.h"

//Printing out all items from the linked list.

void	printlist(node_t *head)
{
	node_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
}

// Adding the first element to the linked list

void	ft_add_first_item(node_t **head, int num)
{
	node_t *first_one;

	first_one = malloc(sizeof(node_t));
	first_one->val = num;
	first_one->next = *head;
	*head = first_one;
}

//Adding just an item to the linked list (of course at the end).

void	ft_add_item(node_t *head, int val)
{
	node_t *current;

	current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	if ((current->next = malloc(sizeof(node_t))) == NULL)
		return ;
	current->next->val = val;
	current->next->next = NULL;
}

//Adding multiple items at a time just at the end of the list.

void	ft_add_last_item(node_t *head)
{
	node_t	*current;
	int		i;

	i = 2;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	
	if ((current->next = malloc(sizeof(node_t))) == NULL)
		return ;
	while (i < 5)
	{
		current->next->val = i;
		current->next->next = malloc(sizeof(node_t));
		current = current->next;
		i++;
	}
	current->next = NULL;
}

int		main(void)
{
	node_t *head = NULL;

	head = malloc(sizeof(node_t));
	if (head == NULL)
		return (1);
	head->val = 1;
	head->next = NULL;
	ft_add_last_item(head);
	printlist(head);
	free(head);
	return (0);
}
