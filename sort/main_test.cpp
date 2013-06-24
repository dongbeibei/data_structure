/*
 * the test of all the sort algorithm
 *
 * author:	dongbeibei
 * time:		2013/6/23
 */


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "sortBase.h"

using namespace std;

void display(ElemType *array, int length);

int main(void)
{
	int array[len];

	srand((unsigned)time(NULL));
	for(int i=0 ; i<len ; i++)
		array[i] = rand() % 50 + 1;

	cout<<"the origin array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;

	//cout<<"--------------bubbleSort-------------\n";
	//bubbleSort(array, len);
	//display(array, len);

	//cout<<"--------------selectSort-------------\n";
	//selectSort(array, len);
	//display(array, len);

	//cout<<"--------------insertSort-------------\n";
	//insertSort(array, len);
	//display(array, len);

	//cout<<"--------------mergeSort-------------\n";
	//mergeSort(array, len);
	//display(array, len);

	//cout<<"--------------quickSort-------------\n";
	//quickSort(array, len);
	//display(array, len);

	//cout<<"--------------heapSort-------------\n";
	//heapSort(array, len);
	//display(array, len);

	//cout<<"--------------countSort-------------\n";
	//countSort(array, len);
	//display(array, len);

	//cout<<"--------------radixSort-------------\n";
	//radixSort(array, len);
	//display(array, len);

	cout<<"--------------bucketSort-------------\n";
	bucketSort(array, len);
	display(array, len);

	return 0;
}

void display(ElemType *array, int length)
{
	cout<<"the result array:\t";
	for(int i=0 ; i<length ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
