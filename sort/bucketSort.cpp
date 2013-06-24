/*
 * the implementation of the bucket sort
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
#include <stdlib.h>
#include <cstring>

struct barrel
{
	int node[10];
	int count;
};

bool bucketSort(ElemType *array, int length)
{
	int	max, min, num, pos;
	int i, j, k;
	struct barrel *pBarrel;

	max = min = array[0];
	for(i=1 ; i<length ; i++)
	{
		if(array[i] > max)
			max = array[i];
		else if(array[i] < min)
			min = array[i];
	}

	num = (max - min + 1)/10 + 1;
	pBarrel = (struct barrel*)malloc(sizeof(struct barrel) * num);
	memset(pBarrel, 0, sizeof(struct barrel) * num);

	for(i=0 ; i<length ; i++)
	{
		k = (array[i] - min + 1)/10;
		(pBarrel + k)->node[(pBarrel+k)->count] = array[i];
		(pBarrel + k)->count++;
	}

	pos = 0;
	for(i=0 ; i<num ; i++)
	{
		quickSort((pBarrel+i)->node, (pBarrel+i)->count);

		for(j=0 ; j<(pBarrel+i)->count ; j++)
			array[pos++] = (pBarrel+i)->node[j];
	}

	free(pBarrel);
}
