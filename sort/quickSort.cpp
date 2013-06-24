/*
 * the implementation of the quick sort
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

void helper(ElemType *array, int start, int end);

bool quickSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	helper(array, 0, length-1);

	return true;
}

void helper(ElemType *array, int start, int end)
{
	if(start >= end)
		return;

	int		i, j, temp;

	i = start;
	j = end;
	temp = array[end];
	while(i < j)
	{
		while(i<j && array[i]<=temp)
			i++;
		array[j] = array[i];
		while(i<j && array[j]>=temp)
			j--;
		array[i] = array[j];
	}
	array[j] = temp;

	helper(array, start, j-1);
	helper(array, j+1, end);
}
