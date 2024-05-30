#include<stdio.h>
#include<stdlib.h>

#define LINKED_LIST(type) typedef struct linked_list_##type\
{\
	type val;\
	linked_list_##type* next;\
}Linked_list_##type;\

LINKED_LIST(int)
LINKED_LIST(char)
LINKED_LIST(float)

#define ADD(type) void add##type(Linked_list_##type** head, type val)\
{\
  	Linked_list_##type* p = (Linked_list_##type*)malloc(sizeof(Linked_list_##type));\
    (*p).val = val;\
    p->next = NULL;\
    if (!*head)\
    {\
	   *head = p;\
	   return;\
    }\
    Linked_list_##type* run = *head;\
    for (; run->next; run = run->next);\
    run->next = p; \
}

ADD(int)
ADD(char)
ADD(float)

#define PRINT_LIST(type,format) void print_list_##type(Linked_list_##type* head)\
{\
	Linked_list_##type* run = head;\
	for (; run; run = run->next)\
	{\
		printf(format, run->val);\
	}\
	printf("\n");\
}

PRINT_LIST(int, "%d,")
PRINT_LIST(char, "%c,")
PRINT_LIST(float, "%f,")

#define ROTATE_LIST(type) void rotate_list_##type(Linked_list_##type** head,int k)\
{\
	Linked_list_##type* run1 = *head;\
	Linked_list_##type* run2 = *head;\
	for (int i = 1; run1->next; i++, run1 = run1->next)\
		if (i == k)\
			run2 = run1;\
	run1->next = *head;\
	*head = run2->next;\
	run2->next = NULL;\
}

ROTATE_LIST(int)
ROTATE_LIST(char)
ROTATE_LIST(float)

int main()
{
	//linked list int
	Linked_list_int* head_int = NULL;
	for (int i = 1; i < 6; i++)
	{
		addint(&head_int, i);
	}
	print_list_int(head_int);
	rotate_list_int(&head_int, 3);
	print_list_int(head_int);

	//linked list char
	Linked_list_char* head_char = NULL;
	for (char i = 'a'; i < 'f'; i++)
	{
		addchar(&head_char, i);
	}
	print_list_char(head_char);
	rotate_list_char(&head_char, 3);
	print_list_char(head_char);

	//linked list float
	Linked_list_float* head_float = NULL;
	for (float i = 1.5; i < 6.5; i++)
	{
		addfloat(&head_float, i);
	}
	print_list_float(head_float);
	rotate_list_float(&head_float, 3);
	print_list_float(head_float);

}