#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "StatementOfFunctions.h"

//Pre order scan
int preOrderScan(node* root, int* res, int index)
{
	if (!root)
		return index;
	res[index++] = root->val;
	index = preOrderScan(root->left, res, index);
	index = preOrderScan(root->right, res, index);
	return index;
}

int* array_to_scan_pre(node* root, size_t size)
{
	int* res = (int*)calloc(sizeof(int), size);
	preOrderScan(root, res, 0);
	return res;
}

//In order scan
int inOrderScan(node* root, int* res, int index)
{
	if (!root)
		return index;
	index = preOrderScan(root->left, res, index);
	res[index++] = root->val;
	index = preOrderScan(root->right, res, index);
	return index;
}

int* array_to_scan_in(node* root, size_t size)
{
	int* res = (int*)malloc(sizeof(int) * size);
	preOrderScan(root, res, 0);
	return res;
}

//Post order scan
int PostOrderScan(node* root, int* res, int index)
{
	if (!root)
		return index;
	res = (int*)realloc(res, (index + 1) * sizeof(int));
	index = preOrderScan(root->left, res, index);
	index = preOrderScan(root->right, res, index);
	res[index++] = root->val;
	return index;
}

int* array_to_scan_post(node* root)
{
	int* res = (int*)malloc(sizeof(int));
	preOrderScan(root, res, 0);
	return res;
}
