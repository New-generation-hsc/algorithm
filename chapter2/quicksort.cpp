#include <iostream>
#include <algorithm>
using namespace std;

/**
 * function to partition an array to two part. the first half is absolute less than a
 * specific number and the seocnd half is absolute grater than the specific number.
 * @param unsorted [the array that should sorted]
 * @param start      [the array first element index]
 * @param last     [the array last element index]
 */
int partition(int *unsorted, int start, int last){
	int left = start, right = last, x = unsorted[start];
	while(left < right){
		while(right>left && unsorted[right] >= x)
			right--;
		unsorted[left] = unsorted[right];
		while(left<right && unsorted[left] <= x)
			left++;
		unsorted[right] = unsorted[left];
	}
	unsorted[left] = x;
	return left;
}

void quicksort(int *unsorted, int start, int last){

	if(start < last){
		int part = partition(unsorted, start, last);
		quicksort(unsorted, start, part-1);
		quicksort(unsorted, part+1, last);
	}
}

int main()
{
	// int arr[] = {4, 8, 3, 7, 1, 5, 2, 6};
	int arr[] = {2, 5, 4, 3, 4};
	int len = sizeof(arr)/sizeof(int);
	quicksort(arr, 0, len-1);
	for(int i = 0; i < len; i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}
/**
 * Harvest: 在进行分解的时候，如果有相等的元素，应该包含 <= 和 >= 
 * 否则会一直循环， left 永远会小于 right
 */