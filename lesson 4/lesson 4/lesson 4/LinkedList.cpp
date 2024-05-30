#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
	int val;
	linked_list* next;
}Linked_list;

void add(Linked_list** head, int val)
{
	Linked_list* p = (Linked_list*)malloc(sizeof(Linked_list));
	(*p).val = val;
	p->next = NULL;
	if (!*head)
	{
		*head = p;
		return;
	}
	Linked_list* run = *head;
	for (; run->next; run = run->next);
	run->next = p;
}

Linked_list* get_node(Linked_list* head, int val)
{
	Linked_list* run = head;
	for (; run && run->val != val; run = run->next);
	return run;
}

void delete_val(Linked_list** head, int val)
{
	if ((*head)->val == val)
	{
		Linked_list* free_p = *head;
		*head = (*head)->next;
		free(free_p);
		return;
	}
	Linked_list* run = *head;
	for (; run->next && run->next->val != val; run = run->next);
	Linked_list* free_p = run->next;
	run->next = run->next->next;
	free(free_p);
}

void print_list(Linked_list* head)
{
	Linked_list* run = head;
	for (; run; run = run->next)
	{
		printf("%d, ", run->val);
	}
	printf("\n");
}

void Rotate_List(Linked_list** head, int k)
{
	Linked_list* run1 = *head;
	Linked_list* run2 = *head;
	for (int i = 1; run1->next; i++, run1 = run1->next)
		if (i == k)
			run2 = run1;
	run1->next = *head;
	*head = run2->next;
	run2->next = NULL;
}

int main()
{
	Linked_list* head = NULL;
	for (int i = 1; i < 6; i++)
	{
		add(&head, i);
		print_list(head);
	}
	Rotate_List(&head, 4);
	print_list(head);
}