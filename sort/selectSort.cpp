/*
 * the implement of selection sort
 *
 * author:	dongbeibei
 * time:		2013/6/22
 * modify time:	2013/6/23
 *
 * input:		1. array[] : ����������
 *			2. length : ���鳤��
 *
 * output:	true: ��ȷ����false: ��������
 */


#include "sortBase.h"

bool selectSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	int		i, j, min;
	int		temp;

	for(i=0 ; i<length-1 ; i++)
	{
		temp = array[i];
		min = i;
		for(j=i+1 ; j<length ; j++)
		{
			if(array[j] < temp)
			{
				min = j;
				temp = array[j];
			}
		}
		array_swap(array, i, min);
	}

	return true;
}
