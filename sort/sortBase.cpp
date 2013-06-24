#include "sortBase.h"

void array_swap(ElemType *array, int i, int j)
{
	if(i == j)
		return;

	ElemType	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
