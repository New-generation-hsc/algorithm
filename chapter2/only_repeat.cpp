#include <iostream>
using namespace std;


/**
 * Input: {1, 2, 3, 4, 4}
 * Output: 4
 * Input: {1, 1, 2, 3, 4}
 * Output: 1
 */

/**
 * finding the repeating element in an array
 * @param  arr [array]
 * @param len [the length of array]
 * @return     [the repeating element]
 */
int onlyrepeat(int *arr, int len){

	int j = 1;
	while(j<len && arr[j] != arr[j-1]){
		j++;
	}
	return arr[j];
}

/**
 * Premise: a sorted array of n elements in range from 1 to n-1
 */

int findRepeatElement(int arr[], int low, int high){

	if(low > high)
		return -1;

	int middle = (low+high)>>1;
	if(arr[middle] != middle+1){
		if(middle >0 && arr[middle] == arr[middle-1])
			return middle;
		return findRepeatElement(arr, low, middle-1);
	}
	return findRepeatElement(arr, middle+1, high);
}

/**
 * Version 3: using ^
 */

int findRepeating(int arr[], int len){

	int res = arr[0];
	for(int i=1; i<len; i++){
		res ^= i;
		res ^= arr[i];
	}
	return res;
}

int main(){
	int arr[] = {1, 2, 3, 4, 4};
	int len = sizeof(arr)/sizeof(int);
	int repeat = findRepeating(arr, len);
	cout<<repeat<<endl;
	return 0;
}

