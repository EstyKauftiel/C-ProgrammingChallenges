#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "StatementOfFunctions.h"

//בניית עץ שאינו עץ סכום מדפיס 0 
void add(node** root, int val)
{
	if (!*root)
	{
		*root = (node*)calloc(sizeof(node), 1);
		(*root)->val = val;
		return;
	}
	if (val < (*root)->val)
		add(&(*root)->left, val);
	else
		add(&(*root)->right, val);
}

//בניית עץ סכום מדפיס 1
int count = 0;
node* build(node** root1, node** root2)
{
	node* newRoot1 = (node*)calloc(sizeof(node), 1);
	newRoot1->val = ((*root1)->val) + ((*root2)->val);
	count++;
	newRoot1->left = *root1;
	newRoot1->right = *root2;
	if (count == 2)
		return newRoot1;
	node* newRoot2 = (node*)calloc(sizeof(node), 1);
	node* n1 = (node*)calloc(sizeof(node), 1);
	n1->val = 22;
	node* n2 = (node*)calloc(sizeof(node), 1);
	n2->val = 5;
	newRoot2->val = n1->val + n2->val;
	newRoot2->left = n1;
	newRoot2->right = n2;
	build(&newRoot1, &newRoot2);
}