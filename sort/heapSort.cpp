/*
 * the implementation of the heap sort
 * 
 * author:	dongbeibei
 * time:		2013/6/24
 *
 * input:		1. array[] : 待排序数组
 *			2. length : 数组长度
 *
 * output:	true: 正确排序；false: 输入有误
 */

#include "sortBase.h"

#define PARENT(i) (i-1)/2
#define LEFT(i) i*2+1
#define RIGHT(i) i*2+2

void heap_swap(ElemType *array, int i, int j);
void max_heapify(ElemType *array, int length, int i);
void build_max_heap(ElemType *array, int length);

bool heapSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	build_max_heap(array, length);
	
	for(int i=length-1; i>0 ; i--)
	{
		heap_swap(array, 0, i);
		
		length--;
		max_heapify(array, length, 0);
	}

	return true;
}

void heap_swap(ElemType *array, int i, int j)
{
	ElemType	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void max_heapify(ElemType *array, int length, int i)
{
	int		left, right, largest;

	left = LEFT(i);
	right = RIGHT(i);

	if(left<=length-1 && array[left]>array[i])
		largest = left;
	else
		largest = i;
	if(right<=length-1 && array[right]>array[largest])
		largest = right;

	if(largest != i)
	{
		heap_swap(array, i, largest);
		max_heapify(array, length, largest);
	}
}

void build_max_heap(ElemType *array, int length)
{
	for(int i=length/2-1 ; i>=0 ; i--)
		max_heapify(array, length, i);
}
