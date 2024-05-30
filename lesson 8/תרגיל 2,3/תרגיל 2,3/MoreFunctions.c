#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "StatementOfFunctions.h"

int CheckIfSumTree(node* root)
{
	if (!(root->left) || !(root->right))
		return 1;
	if (root->val != (root->left->val + root->right->val))
		return 0;
	return CheckIfSumTree(root->left) * CheckIfSumTree(root->right);
}

void printInOrder(node* root)
{
	if (!root)
		return;
	printInOrder(root->left);
	printf("%d,", root->val);
	printInOrder(root->right);
}

int getSize(node* root)
{
	if (!root)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

void printArray(int* res, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d,", res[i]);
	}
	printf("\n");
}