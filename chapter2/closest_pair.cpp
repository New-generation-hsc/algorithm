#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * finding the closest pair point in an array in the interval of [low, high]
 * @param  arr  [array]
 * @param  low  [the lower of interval]
 * @param  high [the higher of interval]
 * @return      [return the distance of the closest pair]
 */
int closest_pair(int *arr, int low, int high){

	if(low >= high) return INT_MAX;
	if(high - low == 1) return arr[high] - arr[low];

	int middle = (low+high)>>1;
	int left_dis = closest_pair(arr, low, middle);
	int right_dis = closest_pair(arr, middle+1, high);
	int middle_dis = arr[middle+1] - arr[middle];

	return min(middle_dis, min(left_dis, right_dis));
}

int main()
{
	int arr[] = {1, 3, 7, 18, 18, 64, 65, 81};
	int len = sizeof(arr)/sizeof(int);
	int distance = closest_pair(arr, 0, len-1);
	cout<<distance<<endl;

	return 0;
}

/**
 * Test case 1: arr[] = {1, 3, 7, 18, 27, 64, 65, 81, 81}  ==> 0;
 * Test case 2: arr[] = {1, 3}; ==> 2;
 * Test case 3: arr[] = {1}; ==> INT_MAX
 */