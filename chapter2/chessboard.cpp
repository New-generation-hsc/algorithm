#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAX_SIZE = 100;
const int SIZE = 4;
int Board[MAX_SIZE][MAX_SIZE];
int tile = 0; // use number to represent the tile

void chessBoard(int top, int left, int row, int col, int size){
	
	/**
	 * top and left: represent the the chessboard top left coordinate
	 * row and col: represent the cooordinate of the different chess.
	 * size: represent the size of the chessboard
	 */
	if(size == 1) return;
	int t = ++tile, s = size/2;
	if(row < top+s && col < left+s)
		chessBoard(row, col, top, left, s);
	else{
		Board[top+s-1][left+s-1] = t;
		chessBoard(top, left, top+s-1, left+s-1, s);
	}
	if(row < top+s && col >= left+s)
		chessBoard(top, left+s, row, col, s);
	else{
		Board[top+s-1][left+s] = t;
		chessBoard(top, left+s, top+s-1, left+s, s);
	}
	if(row >= top+s && col < left+s)
		chessBoard(top+s, left, row, col, s);
	else{
		Board[top+s][left+s-1] = t;
		chessBoard(top+s, left, top+s, left+s-1,s);
	}
	if(row >= top+s && col >= left+s)
		chessBoard(top+s, left+s, row, col, s);
	else{
		Board[top+s][left+s] = t;
		chessBoard(top+s, left+s, top+s, left+s, s);
	}
}

int main(){
	chessBoard(0, 0, 0, 0, SIZE);
	for (int i = 0; i<SIZE; i++)
		{
			for(int j = 0; j<SIZE; j++)
					cout<<Board[i][j]<<"  ";
				cout<<endl;
		}
}