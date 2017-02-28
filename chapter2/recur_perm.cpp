#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void print(const int *v, const int size)
{
	for(int i = 0; i< size; i++)
		printf("%4d", v[i]);
	cout<<endl;
}

void permute(int *v, const int start, const int end){

	if(start == end -1)
		print(v, end);
	else
		for(int i = start; i < end; i++)
		{
			swap(v[start], v[i]);
			permute(v, start+1, end);
			swap(v[start], v[i]);
		}
}

int main()
{
	const int N = 4;
	int value[4];
	for(int i = 0; i<N; i++)
		value[i] = i;
	permute(value, 0, N);
}
