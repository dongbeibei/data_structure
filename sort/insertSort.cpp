/*
 * the implementation of the insert sort
 * 
 * author:	dongbeibei
 * time:		2013/6/23
 *
 * input:		1. array[] : ����������
 *			2. length : ���鳤��
 *
 * output:	true: ��ȷ����false: ��������
 */

#include "sortBase.h"

bool insertSort(ElemType *array, int length)
{
	if(!array || length<=0)
		return false;

	int		i, j, temp;

	for(i=1 ; i<length ; i++)
	{
		temp = array[i];
		for(j=i-1 ; j>=0 ; j--)
		{
			if(array[j] > temp)
				array[j+1] = array[j];
			else
				break;
		}
		array[j+1] = temp;
	}

	return true;
}
