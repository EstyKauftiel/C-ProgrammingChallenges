#pragma once
#include "Struct.h"

int CheckIfSumTree(node* root);
void printInOrder(node* root);
int getSize(node* root);
void printArray(int* res, size_t size);
int preOrderScan(node* root, int* res, int index);
int* array_to_scan_pre(node* root, size_t size);
int inOrderScan(node* root, int* res, int index);
int* array_to_scan_in(node* root, size_t size);
int PostOrderScan(node* root, int* res, int index);
int* array_to_scan_post(node* root);
void add(node** root, int val);
node* build(node** root1, node** root2);

