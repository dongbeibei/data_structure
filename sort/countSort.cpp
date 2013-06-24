/*
 * the implementation of the counting sort
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

bool countSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	ElemType *temp = new ElemType[length];
	int *key = new int[50];
	int i;

	for(i=0 ; i<50 ; i++)
		key[i] = 0;
	for(i=0 ; i<length ; i++)
		key[array[i]]++;
	for(i=1 ; i<50 ; i++)
		key[i] += key[i-1];
	for(i=length-1 ; i>=0 ; i--)
	{
		temp[key[array[i]]] = array[i];
		key[array[i]]--;
	}

	for(i=0 ; i<length ; i++)
		array[i] = temp[i];

	delete []temp;
	delete []key;

	return true;
}
