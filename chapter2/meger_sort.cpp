#include <iostream>
#include <algorithm>
using namespace std;

/**
 * sort array from start to end(length - 1)
 * we have to use a sort array to store the already sorted elements
 * then we copy the sorted elements to origin unsorted array
 */

/*
In this program, if we want to get the middle, >>1 not >>2!!!!!
 */
void merge(int *unsorted, int start, int last, int *sorted){
	int middle = (start+last)>>1;
	int i = start, j = middle+1, index = 0;
	while(i<=middle && j<=last){
		if(unsorted[i] < unsorted[j])
			sorted[index++] = unsorted[i++];
		else
			sorted[index++] = unsorted[j++];
	}
	while(i<=middle)
		sorted[index++] = unsorted[i++];
	for(int k= 0; k<index; k++)
		unsorted[start+k] = sorted[k];
}

void merge_sort(int *unsorted, int start, int end, int *sorted){

	if(start < end)
	{
		int middle = (start + end)>>1;
		cout<<middle<<endl;
		merge_sort(unsorted, start, middle, sorted);
		merge_sort(unsorted, middle+1, end, sorted);
		merge(unsorted, start, end, sorted);
	}
}

int main(){
	int arr[] = {4, 8, 3, 7, 1, 5, 2, 6};
	int len = sizeof(arr)/sizeof(int);
	int sortarray[8];
	merge_sort(arr, 0, len-1, sortarray);
	for(int i=0; i<len; i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}