/*
 * the implementation of the radix sort
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
#include <math.h>
#include <iostream>

int getLoopTimes(int num);
int findMaxNum(ElemType *array, int length);
void sort(ElemType *array, int length, int loop);

bool radixSort(ElemType *array, int length)
{
	int maxNum, loopTimes, i;

	maxNum = findMaxNum(array, length);
	loopTimes = getLoopTimes(maxNum);

	for(i=1 ; i<=loopTimes ; i++)
		sort(array, length, i);
}

int getLoopTimes(int num)
{
	int count, temp;

	count = 1;
	temp = num/10;
	while(temp != 0)
	{
		count++;
		temp /= 10;
	}

	return count;
}

int findMaxNum(ElemType *array, int length)
{
	int i, max;

	max = 0;
	for(i=0 ; i<length ; i++)
	{
		if(array[i] > max)
			max = array[i];
	}

	return max;
}

void sort(ElemType *array, int length, int loop)
{
	int buckets[10][20] = {};
	int tempNum = (int)pow(10, loop-1);
	int i, j;

	for(i=0 ; i<length ; i++)
	{
		int row_index = array[i]/tempNum%10;
		for(j=0 ; j<20 ; j++)
		{
			if(!buckets[row_index][j])
			{
				buckets[row_index][j] = array[i];
				break;
			}
		}
	}

	int k = 0;
	for(i=0 ; i<10 ; i++)
	{
		for(j=0 ; j<20 ; j++)
		{
			if(buckets[i][j])
			{
				array[k] = buckets[i][j];
				buckets[i][j] = 0;
				k++;
			}
		}
	}
}
