#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "StatementOfFunctions.h"

#define DEBUG

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

#ifdef DEBUG
	printf("end to print a sum tree \n \n");
#endif // DEBUG

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

#ifdef DEBUG
	printf("end to print a normal tree \n \n");
#endif // DEBUG

	int size = getSize(newRoot);
	printf("Pre order scan: \n");
	printArray(array_to_scan_pre(newRoot, size), size);
	printf("In order scan: \n");
	printArray(array_to_scan_in(newRoot, size), size);
	printf("Post order scan: \n");
	printArray(array_to_scan_post(newRoot), size);

#ifdef DEBUG
	printf("end to print in all scan options with a dinamic array \n");
#endif // DEBUG

}