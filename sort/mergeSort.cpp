/*
 * the implementation of the merge sort
 * 
 * author:	dongbeibei
 * time:		2013/6/23
 *
 * input:		1. array[] : 待排序数组
 *			2. length : 数组长度
 *
 * output:	true: 正确排序；false: 输入有误
 */

#include "sortBase.h"

void helper(ElemType *array, ElemType *array_temp, int start, int end);
void merge(ElemType *array, ElemType *array_temp, int start, int mid, int end);

bool mergeSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	ElemType *array_temp = new ElemType[length];
	helper(array, array_temp, 0, length-1);

	delete []array_temp;	
	return true;
}

void helper(ElemType *array, ElemType *array_temp, int start, int end)
{
	if(start >= end)
		return;

	int		mid = start + (end - start)/2;

	helper(array, array_temp, start, mid);
	helper(array, array_temp, mid+1, end);

	merge(array, array_temp, start, mid, end);
}

void merge(ElemType *array, ElemType *array_temp, int start, int mid, int end)
{
	int		i , j, k;

	i = k = start;
	j = mid + 1;

	while(i<=mid && j<=end)
	{
		if(array[i] < array[j])
			array_temp[k++] = array[i++];
		else
			array_temp[k++] = array[j++];
	}

	while(i<=mid)
		array_temp[k++] = array[i++];
	while(j<=end)
		array_temp[k++] = array[j++];

	for(k=start ; k<=end ; k++)
		array[k] = array_temp[k];
}
