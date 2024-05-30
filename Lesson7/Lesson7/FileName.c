
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generic_compare(void* val1, void* val2, size_t size)
{
	char* val1_c = (char*)val1;
	char* val2_c = (char*)val2;
	for (int i = 0; i < size; i++)
		if (*(val1_c + i) != *(val2_c + i))
			return -1;
	return 1;
}

int generic_get_val(void* arr, int length, size_t size, int (*compare_ptr)(void*, void*, size_t),void* val )
{
	for (int i = 0; i < length; i++)
		if (compare_ptr((char*)val, ((char*)arr) + (i * size), size) >=0) 
			return i;
	return 0;
}

struct item
{
	char* name;
	double price;
	int count;
};

typedef struct item Item;

int compare_items(void* a, void* b, size_t size)
{
	Item* a_i = (Item*)a;
	Item* b_i = (Item*)b;
	return strcmp(a_i->name, b_i->name);
}

int main()
{
	const int arr_length = 6;
	int arr[] = { 12,9,10,3,8,1 };
	int number = 10;
	printf("int: %d \n", generic_get_val(arr, arr_length,sizeof(int), generic_compare,&number));

	const int str_length = 8;
	char str[9] = "lesson 7";
	char c[2] = "n";
	printf("string: %d \n", generic_get_val(str, str_length, sizeof(char), generic_compare, &c));
	
	Item items[3];
	const int items_length = 3;
	struct item Pasta;
	Pasta.name = (char*)malloc(6);
	strcpy_s(Pasta.name, 6, "Pasta");
	Pasta.price = 3.6;
	Pasta.count = 100;
	items[0] = Pasta;

	struct item Ptitm;
	Ptitm.name = (char*)malloc(6);
	strcpy_s(Ptitm.name, 6, "Ptitm");
	Ptitm.price = 2.5;
	Ptitm.count = 75;
	items[1] = Ptitm;

	struct item Rice;
	Rice.name = (char*)malloc(5);
	strcpy_s(Rice.name, 5, "Rice");
	Rice.price = 5.5;
	Rice.count = 80;
	items[2] = Rice;

	char* name = "Pasta";
	int index = generic_get_val(items, items_length, sizeof(Item), generic_compare, &name);
	printf("the item index: %d ,the item name: %s",index,items[index].name);
}