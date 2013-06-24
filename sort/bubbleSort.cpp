/*
 * the implementation of the bubbling sort
 * 
 * author:	dongbeibei
 * time:		2013/6/22
 *
 * input:		1. array[] : 待排序数组
 *			2. length : 数组长度
 *
 * output:	true: 正确排序；false: 输入有误
 */

#include "sortBase.h"

bool bubbleSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	int 	i, j;
	int		temp;

	for(i=0 ; i<length-1 ; i++)
	{
		for(j=0 ; j<length-i-1; j++)
		{
			if(array[j+1] < array[j])
			{
				array_swap(array, j, j+1);
			}
		}
	}

	return true;
}
