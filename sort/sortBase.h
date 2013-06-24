#ifndef _SORTBASE_H
#define _SORTBASE_H

#define ElemType int
#define len	20

//swap
void array_swap(ElemType *array, int i, int j);
//bubble sort
bool bubbleSort(ElemType *array,int length);
//select sort
bool selectSort(ElemType *array, int length);
//insert sort
bool insertSort(ElemType *array, int length);
//merge sort
bool mergeSort(ElemType *array, int length);

//quick sort
bool quickSort(ElemType *array, int length);
//heap sort
bool heapSort(ElemType *array, int length);
//counting sort
bool countSort(ElemType *array, int length);
//radix sort
bool radixSort(ElemType *array, int length);
//bucket sort
bool bucketSort(ElemType *array, int length);

#endif
