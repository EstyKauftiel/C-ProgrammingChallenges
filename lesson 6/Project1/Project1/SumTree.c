
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};
typedef struct node node;

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

//Pre order scan
int preOrderScan(node* root,int* res,int index)
{
	if (!root)
		return index;
	res[index++] = root->val;
	index= preOrderScan(root->left, res, index);
	index = preOrderScan(root->right, res, index);
	return index;
}

int* array_to_scan_pre(node* root, size_t size)
{
	int* res = (int*)calloc(sizeof(int),size);
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
	int* res = (int*)malloc(sizeof(int)*size);
	preOrderScan(root, res, 0);
	return res;
}

//Post order scan
int PostOrderScan(node* root, int* res, int index)
{
	if (!root)
		return index;
	res = (int*)realloc(res, (index + 1)*sizeof(int));
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

int getSize(node* root)
{
	if (!root)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

void printArray(int* res,size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d,", res[i]);
	}
	printf("\n");
}

int main()
{
	//בניית עץ סכום מדפיס 1
	node* root1 = (node*)calloc(sizeof(node), 1);
	root1->val = 10;
	node* root2 = (node*)calloc(sizeof(node), 1);
	root2->val = 15;
	node* newRoot = build(&root1, &root2);
	printInOrder(newRoot);
	printf("\n");
	printf("%d", CheckIfSumTree(newRoot));
	printf("\n");

	//בניית עץ שאינו עץ סכום מדפיס 0 
	node* root = NULL;
	add(&root, 6);
	add(&root, 3);
	add(&root, 7);
	add(&root, 1);
	add(&root, 9);
	add(&root, 8);
	add(&root, 5);
	add(&root, 2);
	printInOrder(root);
	printf("\n");
	printf("%d", CheckIfSumTree(root));
	printf("\n");

	int size = getSize(newRoot);
	printf("Pre order scan: \n");
	printArray(array_to_scan_pre(newRoot, size), size);
	printf("In order scan: \n");
	printArray(array_to_scan_in(newRoot, size),size);
	printf("Post order scan: \n");
	printArray(array_to_scan_post(newRoot),size);
}