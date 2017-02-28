#include <iostream>
#include <cstdio>
using namespace std;

void print(const int *v, const int size)
{
	for(int i = 0; i< size; i++)
		printf("%4d", v[i]);
	cout<<endl;
}

void visit(int *value, int N, int k)
{
	static int level = -1;
	level += 1;
	value[k] = level;

	if(level == N)
		print(value, N);
	else
		for(int i = 0; i < N; i++)
			if(value[i] == 0)
				visit(value, N, i);

	level = level -1;
	value[k] = 0;
}

int main()
{
	const int N = 4;
	int value[4];
	for(int i = 0; i<N; i++)
		value[i] = 0;
	visit(value, N, 0);
}